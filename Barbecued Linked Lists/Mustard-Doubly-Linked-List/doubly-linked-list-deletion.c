//Program discusses how we can delete a node in a Doubly Linked List.

#include<stdio.h>		//Standard library for Input/Output.
#include<stdlib.h>		//Standard library for functions related to Dynamic Memory Allocation.

struct node *delete_node(struct node *start, int item);		//Declaration, so the program knows we are gonna use it below.

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
	//Now we'll dynamically allocate memory to three nodes, so we acn illustrate
	//the use of free() to remove the space after delelting the node from list.

	struct node *n1;		//Pointer to the n1 node.
	n1 = (struct node *)malloc(sizeof(struct node));	//Dynamic allocation iof space equal to node size
														//, the pointer is returned to n1.

	struct node *n2;		//Pointer to the n2 node.
	n2 = (struct node *)malloc(sizeof(struct node));	//Dynamic allocation iof space equal to node size
														//, the pointer is returned to n2.

	struct node *n3;		//Pointer to the n3 node.
	n3 = (struct node *)malloc(sizeof(struct node));	//Dynamic allocation iof space equal to node size
														//, the pointer is returned to n3.


	int item;				//Variable to hold the node's info which is to be deleted.
	
	start = n1;				//Start points to the first node n1.

	n1->info = 1;			//The value of first node.

	n1->prev = NULL;		//The prev pointer of first node is NULL.

	n1->next = n2;			//n1's next pointer points to n2.

	n2->info = 2;
	n2->prev = n1;			//prev pointer of n2 points to n1.

	n2->next = n3;			//next pointer of n2 points to n3.

	n3->info = 3;
	n3->prev = n2;			//prev pointer of n3 points to n2.

	n3->next = NULL;			//next pointer of n3(last node) points to NULL.

	printf("Enter the item to delete: ");
	scanf("%d", &item);

	start = delete_node(start, item);		//start is returned as it's the only way of accessing the 
											//list so we can know its current position when the list is modified.
											//start pointer and the item of node to be deleted is passed as argumenets.

	display(start);			//To diplay the Linked List afer required deletion.

	return 0;				//return 0 as the main() return Int.
}

struct node *delete_node(struct node *start, int item){		//Actual definition of our function.
	
	struct node *temporary;		//This pointer points to the node to be deleted and freed later. 
	
	if(start == NULL){			//If the list is empty.

		printf("List is empty.\n");
		return start;			//Return start to main().

	}
	
	if(start->next == NULL){			//If there's only one node in the List.

		if(start->info == item){		//If that node is the 'item' we have to delete.

			temporary = start;			//Store it's address in temporary
			
			start = NULL;				//Now, there's no node in the list so start points to NULL.

			free(temporary);			//free the dynamically allocated space to the deleted node using free().

			return start;				//return start to main().
		}

		else{							//If the only node is not the one we have to delelte.

			printf("Item not in the list.\n");
			return start;				//return start to main().
		}
	}

	if(start->info == item){		//If the node we wish to delelte is the first node of the List.

		temporary = start;			//Store it's address in temporary.

		start = start->next;		//Now start points to the second node in the list(which 
									//has become the first node after deletion of current first node).

		start->prev = NULL;			//The new first node's prev pointer is NULL.

		free(temporary);			//free the dynamically allocated memory of the first node using free().

		return start;				//return start to main().
	}

	//If the node is in between the list.

	temporary = start->next;		//assign the second node to the temporary.

	while(temporary->next!=NULL){				//Loop through till the second last element of List.

		if(temporary->info == item){			//If the current 'pointed to' node matches 'item' to be deleted.

			temporary->prev->next = temporary->next;		//The previous node of temporary points to the node next to temporary.

			temporary->next->prev = temporary->prev;		//The node next to temporary points to temporary's previous node.

			free(temporary);		//Free the space allocated to the deleted(temporary) node using free().
			
			return start;			//Return start to main().

		}
		temporary = temporary->next;		//Increment temporary to next node.

	}

	//Now temporary points to the end node of the list.

	if(temporary->info == item){		//If the last node is the node to be deleted.

		temporary->prev->next = NULL;	//Then set the next pointer of node previous to temporary as NULL
										//as now it has become the last node.
		
		free(temporary);				//Free the space dynamically allocated to temporary using free().

		return start;					//Return start to main().

	}
	printf("Element %d not found in the list.\n", item);
	return start;		//Return start to main() even if there is no match of 'item' in the List.
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












