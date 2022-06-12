//level order traversal of a BST.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define QUEUE_SIZE 200

//structure of a node of a bst.
struct bstNode
{
    int data;
    struct bstNode *left;
    struct bstNode *right;
};

//fucnction to create a new bstNode and return its ptr.
struct bstNode *getNewNode(int x)
{
    struct bstNode *temp = (struct bstNode *)malloc(sizeof(struct bstNode));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//function to insertNode in the bst. returns ptr to the root node.
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

//functions to print bst in a structured manner.
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
        printBst(node->left, spaceCount + 10);
    }
    return;
}

//creating a queue of array of type struct bstNode.
struct bstNode *Queue[QUEUE_SIZE];
int front = -1, rear = -1;

//printQueue function
void printQueue()
{
    if (front == -1)
    {
        printf("List is empty\n");
        return;
    }
    int i = front;
    printf("Queue front =>");
    for (i;; i = (i + 1) % QUEUE_SIZE)
    {
        printf("%d ", Queue[i]->data);
        if (i == rear)
        {
            break;
        }
       
    }
    printf("\n");
    return;
}

//enqueue function
void enQueue(struct bstNode *ptr)
{
    if(!ptr){return;};
    if (front == -1)
    {
        front = (front + 1) % QUEUE_SIZE;
        rear = (rear + 1) % QUEUE_SIZE;
        Queue[rear] = ptr;
        return;
    }
    //if next of rear is front then the Queue is full.no more enQueue.
    if ((rear + 1) % QUEUE_SIZE == front)
    {
        printf("Error : cant'Enqueue , list is full\n");
        return;
    }
    rear = (rear + 1) % QUEUE_SIZE;
    Queue[rear] = ptr;

  
    return;
}

//dequeue function.
void deQueue()
{
    if (front == -1) //if list is empty.
    {
        printf("Error: cannot deQueue , lisft is empty\n");
        return;
    }
    if (front == rear) //if list has only one element.
    {
        front = rear = -1;
        return;
    }
    front = (front + 1) % QUEUE_SIZE;
   
    return;
}

//level order Traversal.
void levelOrder(struct bstNode* node)
{
    if(!node)
    {
        printf("The Tree is Empty\n");
        return;
    }
    enQueue(node);
    while(!(front == -1))
    {
       

        printf("%d ",Queue[front]->data);
        enQueue(Queue[front]->left);
        enQueue(Queue[front]->right);
        deQueue();
       
    }
    return;
}

int main()
{
    struct bstNode *root = NULL;
    int element;
    while (1)
    {
        printf("What do you want to do to the BST\n1 => insertNode\n2 => printBst\n3 => level Order Traversal\n");
        scanf("%d", &element);

        switch (element)
        {
        case 1:
            printf("give us the element to insert\t");
            scanf("%d", &element);
            root = insertNode(root, element);
            break;
        case 2:
            printBst(root, 0);
            break;
        case 3:
            levelOrder(root);
            break;
        default:
            printf("Error: wrong Input\n");
            break;
        }
    }
}
