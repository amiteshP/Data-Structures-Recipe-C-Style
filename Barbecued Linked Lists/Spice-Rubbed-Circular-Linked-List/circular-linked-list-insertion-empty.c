//Program discusses how to insert a new node into an empty Circular Linked List.

#include<stdio.h>		//Library for standard Input/Output Functions.

#include<stdlib.h>		//Standard library for dynamically memory allocations.

void display(struct node *last);	//A function used to display the list, can be found in file
									//circular-linked-list-traversal.c in the italian linked list flavour.

struct node{				//We define the structure of the node.

	int info;				//Data part of the node.

	struct node *link;		//The link part of the node.
};

int main(){
	struct node *last = NULL;		//In circular linked list we have a "last pointer", which
									//points to the last node of the list. This marks the end.
									//It's equal to NULL as the list is currently empty.
	
	struct node *new_node;			//pointer to our new_node.

	int data;						//Variable we will use to hold the data to be entered into the new_node.

	printf("Enter the data to be entered into the new_node: ");
	scanf("%d", &data);

	new_node = (struct node*)malloc(sizeof(struct node));		//Allocating space equal to the node size to the 
																//new_node and returning pointer to the new_node pointer.
	
	new_node->info = data;			//Enter the data into the new_node.

	last = new_node;				//As the new_node is the only node(first and last) in 
									//the list, last pointer points to it.
	
	new_node->link = new_node;		//As the new_node is the only node, it points to itself.

	display(last);					//We pass last pointer to it, to access and display the list(here, only one node).

	return 0;						//Return 0 as main() returns an int value.
}

void display(struct node *last){	//Actual definition of our funtion.

	struct node *ptr;				//Pointer which will point to the node which will be displayed currently.(throguh the loop)

	if(last == NULL){					//If there's no element in the list.

		printf("The list is empty.");
		return;
	}

	ptr = last->link;				//pointer points to the first node.

	//Use do-while loop as we want the loop to run at least once.
	
	do{
		printf("%d  ", ptr->info);		//Print the data of current node.

		ptr = ptr->link;				//Increment to the next Node.
	}
	while(ptr != last->link);			//Loop till the pointer points to the first node again.
}
