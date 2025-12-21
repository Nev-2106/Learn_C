#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define Node, newNode, findNode here */
struct Node {
    char *word;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(char *word) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->word = (char*)malloc(strlen(word) + 1);
    strcpy(node->word, word);
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* findNode(struct Node *root, char *target) {
    if (root == NULL) {
        return NULL;
    }
    int cmp = strcmp(target, root->word);
    if (cmp == 0) {
        return root;
    } else if (cmp < 0) {
        return findNode(root->left, target);
    } else {
        return findNode(root->right, target);
    }
}

int main()
{
    struct Node *l    = newNode("left");
    struct Node *r    = newNode("right");
    struct Node *root = newNode("middle");
    root->left  = l;
    root->right = r;

    printf("%s\n", findNode(root,   "left")->word);
    printf("%s\n", findNode(root, "middle")->word);
    printf("%s\n", findNode(root,  "right")->word);
    struct Node *found = findNode(root, "none");
    if (found == NULL) {
        printf("0x0\n");
    } else {
        printf("%p\n", (void*)found);
    }

    return 0;
}
