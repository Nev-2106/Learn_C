#include <stdio.h>

/* define Node here */
 typedef struct Node{
    char *word;
    Node *left;
    Node *right;
};

int main()
    {
        Node l = {  "left",  0,  0 };
        Node r = { "right",  0,  0 };
        Node n = {  "root", &l, &r };
        Node *root = &n;

        printf("%s\n", root->left->word);
        printf("%s\n", root->right->word);
        printf("%s\n", root->word);

        return 0;
    }
