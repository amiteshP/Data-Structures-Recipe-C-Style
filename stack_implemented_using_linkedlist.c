#include<stdio.h>
#include<stdlib.h>
struct node{
	int key;
	struct node *next;
};
struct node *top=NULL;
void push(int item)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->key=item;
	temp->next=top;
	top=temp;	
	printf("Node pushed in Stack: %d\n\n",top->key);
}
void pop()
{
	int data;
	struct node *temp;
	temp=top;
	data=top->key;
	top=top->next;
	free(temp);
	printf("deleted node's data is: %d\n\n",data);
	//return data;	
}
void display()
{
	if(top==NULL)
	printf("Empty Stack ");
	else {
		while(top!=NULL){
		printf("%d",top->key);
		top=top->next;
	}
	}
}
int main()
{
	push(5);
	push(6);
	push(7);
	pop();
	pop();
	display();
	return 0;
}
