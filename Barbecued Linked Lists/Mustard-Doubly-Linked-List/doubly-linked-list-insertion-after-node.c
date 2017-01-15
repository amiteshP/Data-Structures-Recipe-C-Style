//Program discusses how to insert a new node after a mentioned node in between a Doubly Linked List.

#include<stdio.h>		//Library for standard Input/Output functions.
#include<stdlib.h>		//Library for dynamic allocation of memory related functions.

struct node *insert_after(struct node *start, int data, int item);		//Declaration, so the program knows that this is going to be used below.

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

	printf("Enter the node after which the new node is to be inserted: ");
	scanf("%d", &item);
	printf("Enter the data to be inserted in the new node after the mentioned node of the list: ");
	scanf("%d", &data);

	start = insert_after(start, data, item);		//"start" is returned as it can be modified in the modified list
													//and it's the only way of traversing list.
													//current start pointer, data and item are passed as arguments.

	display(start);					//To display the list, start is passed as argument.

	return 0;						//Return 0, as the main function's return type is Int.
}


struct node *insert_after(struct node *start, int data, int item){		//Actual definition of our function.

	struct node *new_node;		//The pointer to the new_node we are going to insert.

	struct node *ptr;			//Pointer to find the node after which we have to insert the new node.

	new_node = (struct node *)malloc(sizeof(struct node));		//Allocating space of size equal to that of node and
																//returning pointer to new_node.

	new_node->info = data;		//Inserting data into the new node.

	ptr = start;				//Now, to reach the "item", first the ptr points to first node.

	while(ptr!=NULL){			//Loop through till we reach the end node which points to NULL.

		if(ptr->info == item){				//If the current 'pointed to' node is the desired 'item'

			new_node->prev = ptr;			//set new_node's prev pointer to current node.

			new_node->next = ptr->next;		//set the next pointer of new_node to the one next to the 
											//current 'item' node after which we have to insert new_node.

			if(ptr->next != NULL)			//check if the 'pointed to' node is NOT the last one.

				ptr->next->prev = new_node;	//Then set the next node's prev pointer to the new_node.

			ptr->next = new_node;			//'pointed to' node points to the new_node.

			return start;					//Return the start pointer.
		}

		ptr = ptr->next;					//Increment the pointer to the next one.
	}
	printf("The desired node %d is not present in the list.", item);

	return start;							//Return start to the main() function.
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