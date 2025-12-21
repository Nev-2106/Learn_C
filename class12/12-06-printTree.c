#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define Node, newNode, findNode, printTree here */
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
        *treep = newNode(word);
        return *treep;
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

void printTree(Node *tree)
{
    if (tree == NULL)
        return;
    
    printTree(tree->left);
    printf("%s\n", tree->word);
    printTree(tree->right);
}

#define indexableSize(A) (sizeof(A) / sizeof(*(A)))

int main()
{
    Node *root = 0;

    char *words[] = {
	"Peter", "Piper", "picked", "a", "peck", "of", "picked", "pepper",
	"where", "is", "the", "peck", "that", "Peter", "Piper", "picked",
    };

    for (int i = 0;  i < indexableSize(words);  ++i)
	findNode(&root, words[i]);

    printTree(root);

    return 0;
}
