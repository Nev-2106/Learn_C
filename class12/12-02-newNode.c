#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define Node, newNode here */
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

int main()
{
    struct Node *l    = newNode("left");
    struct Node *r    = newNode("right");
    struct Node *root = newNode("root");
    root->left  = l;
    root->right = r;

    printf("%s\n", root->left->word);
    printf("%s\n", root->right->word);
    printf("%s\n", root->word);

    return 0;
}
