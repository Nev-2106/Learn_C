#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define Node, newNode, findNode here */
typedef struct Node {
    char *word;
    struct Node *left;
    struct Node *right;
} Node;

Node *newNode(char *word)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->word = (char *)malloc(strlen(word) + 1);
    strcpy(node->word, word);
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *findNode(Node **treep, char *word)
{
    Node *tree = *treep;
    if (tree == NULL) {
        return NULL;
    }
    int cmp = strcmp(word, tree->word);
    
    if (cmp == 0) {
        return tree;
    } else if (cmp < 0) {
        return findNode(&tree->left, word);
    } else {
        return findNode(&tree->right, word);
    }
}
int main()
{
    struct Node *l    = newNode("left");
    struct Node *r    = newNode("right");
    struct Node *root = newNode("middle");
    root->left  = l;
    root->right = r;

    printf("%s\n", findNode(&root,   "left")->word);
    printf("%s\n", findNode(&root, "middle")->word);
    printf("%s\n", findNode(&root,  "right")->word);
    struct Node *found = findNode(&root, "none");
    if (found == NULL) {
        printf("0x0\n");
    } else {
        printf("%p\n", (void*)found);
    }

    return 0;
}
