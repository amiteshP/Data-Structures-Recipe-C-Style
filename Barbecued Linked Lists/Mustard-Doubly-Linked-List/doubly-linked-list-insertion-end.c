//The program discusses about how to insert a new node at the end of a Doubly Linked List.

#include<stdio.h>		//Library for standard Input/Output functions.
#include<stdlib.h>		//Library for dynamic allocation of memory related functions.

struct node *insert_at_end(struct node *start, int data);		//Declaration, so the program knows that this is going to be used below.

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

	int data;						//Variable to hold the info of the node to be added.
	
	struct node n1, n2, n3, n4;		//We declare four nodes for our program.

	start = &n1;					//start, the pointer we defined earlier
									//points to the first node n1.
	n1.info = 1;
	n1.prev = NULL;					//prev pointer of first node points to NULL.
	n1.next = &n2;					//n1's next pointer points to n2.
	n2.info = 2;
	n2.prev = &n1;					//n2's prev pointer points to n1.
	n2.next = &n3;					//n2's next pointer points to n3.
	n3.info = 3;	
	n3.prev = &n2;					//n3's prev pointer points to n2.
	n3.next = &n4;					//n3's next pointer points to n4.
	n4.info = 4;
	n4.prev = &n3;					//n4's prev pointer points to n3.
	n4.next = NULL;					//n4's pointer, pointer of last node, points to NULL
									//, to indicate the end of the Linked List.

	printf("Enter the data to be inserted in the new node at the end of the list: ");
	scanf("%d", &data);

	start = insert_at_end(start, data);		//"start" is returned as it can be modified in the modified list
													//and it's the only way of traversing list.
													//current start pointer and data is passed as arguments.

	display(start);					//To display the list, start is passed as argument.

	return 0;						//Return 0, as the main function's return type is Int.
}

struct node *insert_at_end(struct node *start, int data){		//Our actual definition of Function

	struct node *new_node;			//Pointer to the new_node we are adding at the end.

	struct node *ptr;				//Pointer which will point to the current last element of the List.

	new_node = (struct node *)malloc(sizeof(struct node));		//Allocating space equal to the node and returning
																//the pointer tot he new_node.

	new_node->info = data;			//Entering the data into the new_node.
	
	ptr = start;					//Now to go through the list, pointer iniitally
									//points to the first element of the list.

	while(ptr->next!=NULL)			//Now loop till we get to the last element which
		ptr = ptr->next;			//points to null, till then we increment the pointer.

	ptr->next = new_node;			//Now the current last node should point to the newly added last node.

	new_node->next = NULL;			//The newly added last node's next pointer should point to NULL.

	new_node->prev = ptr;			//And the newly added last node's prev pointer should point to previous last node.
	
	return start;					//Return start back to main().
}

void display(struct node *start){	//This is the definition of display()
	struct node *ptr;
	if(start == NULL){				//First check if the list is empty
		printf("List is empty.");	//by comparing the start pointer with NULL(empty)
		return;
	}
	ptr = start;					//If not, then we continue to display list
	printf("List is: \n");
	while(ptr != NULL){				//This loop goes on till the last node is encountered
		printf("%d  ", ptr->info);	//after which it points to NULL, and the loop breaks.
		ptr = ptr->next;			//Pointer is incrememnted by pointing to the next pointer.
	}
}