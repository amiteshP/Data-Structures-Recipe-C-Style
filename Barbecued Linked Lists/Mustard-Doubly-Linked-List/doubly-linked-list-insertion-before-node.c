//Program discusses how to insert a new node before a mentioned node in between a Doubly Linked List.

#include<stdio.h>		//Library for standard Input/Output functions.
#include<stdlib.h>		//Library for dynamic allocation of memory related functions.

struct node *insert_before(struct node *start, int data, int item);		//Declaration, so the program knows that this is going to be used below.

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
	
	int item;						//Variable to hold the info of the node after which we wish to insert the new one.

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

	printf("Enter the node before which the new node is to be inserted: ");
	scanf("%d", &item);
	printf("Enter the data to be inserted in the new node before the mentioned node of the list: ");
	scanf("%d", &data);

	start = insert_before(start, data, item);		//"start" is returned as it can be modified in the modified list
													//and it's the only way of traversing list.
													//current start pointer, data and item are passed as arguments.

	display(start);					//To display the list, start is passed as argument.

	return 0;						//Return 0, as the main function's return type is Int.
}


struct node *insert_before(struct node *start, int data, int item){		//Actual definition of our function.

	struct node *new_node;		//Pointer to the new_node we are going to add.

	struct node *ptr;			//Pointer for reaching the node before which we have to add the new_node.

	new_node = (struct node *)malloc(sizeof(struct node));		//Allocating size equal to the size of the node, and
																//returning the pointer to new_node.

	if(start->info == item){		//First we check if the 'item' node is the first node.

		new_node->info = data;		//If yes then the data of new_node is inserted into the new_node.

		new_node->next = start;		//The new_node(first) now points to the previous first node.
	
		new_node->prev = NULL;		//The prev pointer of the new node is NULL as it's the first node.

		start->prev = new_node;		//The previous first node(now second node)'s prev pointer points to new_node.

		start = new_node;			//The start node points to the new_node(first node).

		return start;				//Return start.
	}

	//If the 'item' node is not the first one, then we search it in the List.

	ptr = start;					//Assign start to ptr, as it has to traverse through the whole list.

	while(ptr!=NULL){				//Loop till we the ptr points to NULL(end of list).

		if(ptr->info == item){		//If the 'pointed to' node contains 'item'.

			new_node->info = data;			//Enter the new_node data into new_node.

			new_node->next = ptr;			//The next pointer of new_node points to the 'pointed to' node
											//as the new_node is inserted before it.

			new_node->prev = ptr->prev;		//The prev pointer of the new_node points to the previous node
											//of the 'pointed to node'.

			ptr->prev->next = new_node;		//The next of the previous node(previous to 'pointed to' node)
											//points to the new_node as it is before it.

			ptr->prev = new_node;			//The prev of 'pointed to' node points to the new_node as it's before it.
			
			return start;					//We return start to the main().

		}
		ptr = ptr->next;					//Increment the pointer to the next node.

	}
	printf("%d is not present in the list.\n", item);
	return start;				//Return start to main() even if no node is found matching 'item'.
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


