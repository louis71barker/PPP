#include "binaryTreeSort.h"

void addNode (node **currentNode, int data);
void inOrderTraverse(node *currentNode);
void deleteTree(node *currentnode);
node* createNewNode(int data);

int main()
{
    node *root =  NULL;

    int sortArray[]={1,50,78,3,2,6,8,45,38,5,7};
    int len = sizeof(sortArray)/sizeof(int);
    int i;

    for (i=0;i<len;i++)
    {
        addNode(&root, sortArray[i]);
    }

    inOrderTraverse(root);

    deleteTree(root);

    return EXIT_SUCCESS;
}

void addNode (node **pcurrentNode, int data)
{

    if (*pcurrentNode == NULL)
    {
        node *tmp = createNewNode(data);
        *pcurrentNode = tmp;
    }
    else
    {
        addNode(*pcurrentNode,data);
    }
    if ((*pcurrentNode)->data == data)
    {
        printf("The data is already in the tree \n");
        return;
    }
    if (data < (*pcurrentNode)->data)
    {
            node *tmp = createNewNode(data);
            (*pcurrentNode)->left = tmp;
    }
    else
     {
            node *tmp = createNewNode(data);
            (*pcurrentNode)->right = tmp;
     }
}

node* createNewNode(int data)
{
        node *tmp;
        tmp = (node *)malloc(sizeof(node));
        tmp->data = data;
        tmp->left = NULL;
        tmp->right = NULL;
        return tmp;

}

void inOrderTraverse(node *currentNode)
{
    if(currentNode->left!=NULL)
        inOrderTraverse(currentNode->left);
    printf("%d" , currentNode->data);
    if(currentNode->right!=NULL)
        inOrderTraverse(currentNode->right);

}

void deleteTree(node *currentnode)
{
    if (currentnode == NULL)
        return;
    deleteTree(currentnode->left);
    deleteTree(currentnode->right);
    free(currentnode);
}
