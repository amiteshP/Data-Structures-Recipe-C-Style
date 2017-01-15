//The program discusses how to insert an element in the beginning of the Doubly Liked List.

#include<stdio.h>		//Library for standard Input/Output functions.
#include<stdlib.h>		//Library for dynamic allocation of memory related functions.


struct node *insert_at_beginning(struct node *start, int data);		//Declaration, so the program knows that this is going to be used below.

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

	int data;						//Variable to hold the info of node to be added.

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

	printf("Enter the data to be inserted in the new node at the beginning of the list: ");
	scanf("%d", &data);

	start = insert_at_beginning(start, data);		//"start" is returned as it can be modified in the modified list
													//and it's the only way of traversing list.
													//current start pointer and data is passed as arguments.

	display(start);					//To display the list, start is passed as argument.

	return 0;						//Return 0, as the main function's return type is Int.
}

struct node *insert_at_beginning(struct node *start, int data){		//Actual definition of function.

	struct node *new_node;		//A pointer to point to the new_node we are gonna insert.

	new_node = (struct node *)malloc(sizeof(struct node));		//Allocate size equal to that of a node and return 
																//pointer to the new_node.

	new_node->info = data;		//Insert the data into the node.

	new_node->prev = NULL;		//The previous pointer of the first node should be NULL.

	new_node->next = start;		//The next pointer should point to the next node in the list, 
								//currently pointed by the start.

	start->prev = new_node;		//The next node should point to this new_node.

	start = new_node;			//Finally start should point to the first node
								// of the list, which we just added.

	return start;				//Return the start pointer.
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






