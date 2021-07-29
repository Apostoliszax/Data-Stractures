#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *leftChildren;
    struct node *rightChildren;
};

struct node *CreateNode(int data)
{
    // Allocate memory for new node
    struct node *node = (struct node *)malloc(sizeof(struct node));

    // Assign data to this node
    node->data = data;

    // Initialize left and
    // right children as NULL
    node->leftChildren = NULL;
    node->rightChildren = NULL;
    return (node);
}

int main()
{
    /*create root*/
    struct node *root = CreateNode(1);
    /* following is the tree after above statement
         1
        / \
      NULL NULL
    */

    root->leftChildren = CreateNode(2);
    root->rightChildren = CreateNode(3);
    /* 2 and 3 become left and right children of 1
            1
         /    \
        2      3
      /  \    /  \
   NULL NULL NULL NULL
    */

    root->leftChildren->leftChildren = CreateNode(4);
    root->leftChildren->rightChildren = CreateNode(7);
    /* 4 becomes left child of 2
              1
          /      \
         2        3
      /  \      /  \
   4       7  NULL NULL
 / \      / \
NULLNULLNULL NULL
    */

    getchar();
    return 0;
}