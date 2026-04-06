#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void walk_directory(const char *path) {
    struct stat statbuf;

    // Print the current path
    printf("%s\n", path);

    // Get status of the path to check if it's a directory
    if (stat(path, &statbuf) == -1) {
        perror("stat");
        return;
    }

    // Check if the path is a directory
    if (S_ISDIR(statbuf.st_mode)) {
        DIR *dir = opendir(path);
        if (dir == NULL) {
            perror("opendir");
            return;
        }

        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {
            // Ignore the standard "." and ".." entries
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            // Construct the new path: "parent/child"
            char next_path[1024];
            // Handle the case where root is just "/" to avoid "//"
            if (strcmp(path, "/") == 0) {
                snprintf(next_path, sizeof(next_path), "/%s", entry->d_name);
            } else {
                snprintf(next_path, sizeof(next_path), "%s/%s", path, entry->d_name);
            }

            // Recursive call
            walk_directory(next_path);
        }
        closedir(dir);
    }
}

int main(int argc, char *argv[]) {
    char *start_path;

    if (argc > 1) {
        start_path = argv[1];
    } else {
        start_path = ".";
    }

    walk_directory(start_path);

    return 0;
}