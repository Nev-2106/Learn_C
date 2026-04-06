#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Added search_term parameter to the function
void walk_directory(const char *path, const char *search_term) {
    struct stat statbuf;

    // Logic: If there is no search term, print everything.
    // If there IS a search term, only print if the path contains it.
    if (search_term == NULL || strstr(path, search_term) != NULL) {
        printf("%s\n", path);
    }

    if (stat(path, &statbuf) == -1) {
        return; // Skip entries we can't access
    }

    if (S_ISDIR(statbuf.st_mode)) {
        DIR *dir = opendir(path);
        if (dir == NULL) return;

        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            char next_path[1024];
            // Formatting the path correctly
            if (strcmp(path, "/") == 0) {
                snprintf(next_path, sizeof(next_path), "/%s", entry->d_name);
            } else {
                snprintf(next_path, sizeof(next_path), "%s/%s", path, entry->d_name);
            }

            // Pass the search term down into the recursion
            walk_directory(next_path, search_term);
        }
        closedir(dir);
    }
}

int main(int argc, char *argv[]) {
    char *start_path = ".";
    char *search_term = NULL;

    // Argument handling:
    // 1 arg:  ./listfiles (defaults to "." and no filter)
    // 2 args: ./listfiles /home (path = /home, no filter)
    // 3 args: ./listfiles /home txt (path = /home, filter = txt)
    
    if (argc >= 2) {
        start_path = argv[1];
    }
    if (argc >= 3) {
        search_term = argv[2];
    }

    walk_directory(start_path, search_term);

    return 0;
}