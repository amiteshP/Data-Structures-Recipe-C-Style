//Program discusses how to insert a new node in an empty Doubly Linked List.

#include<stdio.h>		//Library for standard Input/Output functions.
#include<stdlib.h>		//Library for dynamic allocation of memory related functions.

void display(struct node *start);	//A function used to display the list, can be found in file
									//doubly-linked-list-traversal.c in the italian linked list flavour.

struct node{		
	struct node *prev;				//The structure of a doubly linked list
	int info;						//has two pointers, one for previous node
	struct node *next;				//and the other for next node.
};

int main(){

	struct node *start = NULL;		//We define the first node to be
									//the "start" node, which is a pointer
									//to the first node having Data(info).

	int data;			//Variable used to hold data of the node to be added.

	struct node *new_node;		//Pointer to the new_node we are adding in the empty list.

	new_node = (struct node *)malloc(sizeof(struct node));		//Dynamically allocate size equal to the size of
																//node and return the pointer to new_node.

	printf("Enter the data of the new node of the list: ");
	scanf("%d", &data);

	new_node->info = data;		//Enter the data into the node.

	new_node->next = NULL;		//The next pointer of the "only" node in the list should be NULL.

	new_node->prev = NULL;		//The previous 	pointer of the first node should be NULL.

	start = new_node;			//start should point to the first node in the list.

	display(start);				//This function displays the list of nodes.

	return 0;					//We return 0 as the main function's return type is int.
}

void display(struct node *start){	//This is the definition of display().
	
	struct node *ptr;
	
	//Here, we know the list isn't empty, so no need of checking it for that condition.

	ptr = start;					
	printf("List is: \n");
	while(ptr != NULL){				//This loop goes on till the last node is encountered
		printf("%d  ", ptr->info);	//after which it points to NULL, and the loop breaks.
		ptr = ptr->next;			
	}
}




