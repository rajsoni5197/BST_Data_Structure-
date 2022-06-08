//implementing a binary search tree in c.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct bstNode
{
    int data;
    struct bstNode *left;
    struct bstNode *right;
};
struct bstNode *getNewNode(int x)
{
    struct bstNode *temp = (struct bstNode *)malloc(sizeof(struct bstNode));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct bstNode *insertNode(struct bstNode *node, int x)
{
    if (!node)
    {
        node = getNewNode(x);
        return node;
    }
    if (x <= node->data)
        node->left = insertNode(node->left, x);
    if (x > node->data)
        node->right = insertNode(node->right, x);
    return node; //vvi
}

void printSpace(int x)
{
    for (int i = 0; i < x; i++)
    {
        printf(" ");
    }
    return;
}

void printBst(struct bstNode *node, int spaceCount)
{
    // printf("\nhello\n");
    // printf("%d", node->data);
    // printf("\n");

    if (!node)
        printf("Error: can't print bst is empty.\n");
    if (node->right)
    {
        printBst(node->right, spaceCount + 10);
    }
    printSpace(spaceCount);
    printf("%d\n", node->data);
    if (node->left)
    {
        // printf("\nleft\n");
        printBst(node->left, spaceCount + 10);
    }
    return;
}

bool searchBst(struct bstNode *node, int element, int level)
{
    
    if (!node)
    {
        return 0;
    }
    if (element == node->data)
    {
        printf("Found at level %d\n ", level);
        return 1;
    }
    if(element<= node->data)return searchBst(node->left, element, level + 1);

    return searchBst(node->right, element, level + 1);
}

int main()
{
    struct bstNode *root = NULL;
    int element;
    while (1)
    {
        printf("What do you want to do to the BST\n1 => insertNode\n2 => search Element\n3 => printBst\n");
        scanf("%d", &element);

        switch (element)
        {
        case 1:
            printf("give us the element to insert\t");
            scanf("%d", &element);
            root = insertNode(root, element);
            break;
        case 2:
            printf("give us the element to search\t");
            scanf("%d", &element);
            if(!searchBst(root, element, 0))printf("NO match found \n");
            break;
        case 3:
            printBst(root, 0);
            break;
        default:
            printf("Error: wrong Input\n");
            break;
        }

        // printf("give us the element to insert\t");
        // scanf("%d", &element);
        // root = insertNode(root, element);
        // printBst(root, 0);
    }
    // root = insertNode(root,15);
    // insertNode(root,10);insertNode(root,20);
    // insertNode(root,18);
    // insertNode(root,9);
    // insertNode(root,11);
    // insertNode(root,38);

    // printf("%d => %d|%d|%d\n",root,root->left,root->data,root->right);
    // printf("%d => %d|%d|%d\n",root->left,root->left->left,root->left->data,root->left->right);
    // printf("%d => %d|%d|%d\n",root->right,root->right->left,root->right->data,root->right->right);
}
