#include<stdio.h>
#include<stdlib.h>
typedef struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
}node;
 
node *create()
{
    node *tempNode;
    printf("Enter data at Node:");
    tempNode=(node*)malloc(sizeof(node));
    scanf("%d",&tempNode->data);
    tempNode->left=tempNode->right=NULL;
    return tempNode;
}
void insertNode(node *rootNode,node *tempNode)
{
    if(tempNode->data<rootNode->data)
    {
        if(rootNode->left!=NULL)
            insertNode(rootNode->left,tempNode);
        else
            rootNode->left=tempNode;
    }
    
    if(tempNode->data>rootNode->data)
    {
        if(rootNode->right!=NULL)
            insertNode(rootNode->right,tempNode);
        else
            rootNode->right=tempNode;
    }
}
 

 
void preorder(node *rootNode)
{
    if(rootNode!=NULL)
    {
        printf("%d ",rootNode->data);
        preorder(rootNode->left);
        preorder(rootNode->right);
    }
}
 
int main()
{
    char ch;
    node *rootNode=NULL,*tempNode;
    
    do
    {
        tempNode=create();
        if(rootNode==NULL)
            rootNode=tempNode;
        else    
            insertNode(rootNode,tempNode);
            
        printf("Do you want to enter more(y/n)?");
       	getchar();
        scanf("%c",&ch);
    }while(ch=='y'|ch=='Y');
    
    printf("Preorder Traversal: ");
    preorder(rootNode);
    return 0;
}
 


