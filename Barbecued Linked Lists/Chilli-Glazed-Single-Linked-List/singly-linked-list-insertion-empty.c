//This program discusses how to insert a new node to an empty list.

#include<stdio.h>
#include<stdlib.h>

void display(struct node *start);	//A function used to display the list, can be found in file
									//singly-linked-list-traversal.c in the italian linked list flavour.
struct node{
	int info;
	struct node *link;
};

int main(){

	struct node *start = NULL; 	//Initially the start pointer will point to NULL as 
								//it's an empty list.

	struct node *new_node;		//A pointer to the new_node we are gonna add in our empty list.

	int data;			//This integer variable holds the element we wanna enter in new_node.

	printf("Enter the data you wanna enter in the first node of list: ");
	scanf("%d", &data);

	new_node = (struct node *)malloc(sizeof(struct node));	//Assign a memory location for the new_node, same size as
															//the structure of node in our list, and return pointer to new_node.
	
	new_node->info = data;		//Enter data in new_node.
	new_node->link = start;		//The link of the only new_node should point to NULL(or start).
	start = new_node;			//start should now point to new_node.

	display(start);			//Let's see the one node now we have in the list.

	return 0;
}

void display(struct node *start){	//This is the definition of display().
	
	struct node *ptr;
	
	//Here, we know the list isn't empty, so no need of checking it for that condition.

	ptr = start;					
	printf("List is: \n");
	while(ptr != NULL){				//This loop goes on till the last node is encountered
		printf("%d  ", ptr->info);	//after which it points to NULL, and the loop breaks.
		ptr = ptr->link;			
	}
}