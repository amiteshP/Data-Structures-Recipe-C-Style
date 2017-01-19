//Program discusses various cases of deletion of a node from the Circular Linked List.

#include<stdio.h>		//Library for standard Input/Output Functions.

#include<stdlib.h>		//Standard library for dynamically memory allocations.

struct node* deletion(struct node *last, int data);				//Declaration of our funtion so the program
																//knows that it's gonna be used below.

void display(struct node *last);	//A function used to display the list, can be found in file
									//circular-linked-list-traversal.c in the italian linked list flavour.

struct node{				//We define the structure of the node.

	int info;				//Data part of the node.

	struct node *link;		//The link part of the node.
};

int main(){

	struct node *last = NULL;		//In circular linked list we have a "last pointer", which
									//points to the last node of the list. This marks the end.

	int data;						//Variable used to hold the data of the node we wish to delete.

	//Now to illustrate the use of free() funtion to free the dynamically allocated space
	//while deleting a node we are gonna dynamically allocate space to four nodes of our list.

	struct node *n1, *n2, *n3, *n4;			//Structure Pointer to four node.

	n1 = (struct node *)malloc(sizeof(struct node));	//Allocating space to first node.
	n2 = (struct node *)malloc(sizeof(struct node));	//Allocating space to second node.
	n3 = (struct node *)malloc(sizeof(struct node));	//Allocating space to third node.
	n4 = (struct node *)malloc(sizeof(struct node));	//Allocating space to fourth node.
	
	n1->info = 1;
	n1->link = n2;		//n1 node points to n2.

	n2->info = 2;
	n2->link = n3;		//n2 points to n3.

	n3->info = 3;
	n3->link = n4;		//n3 points to n4.

	n4->info = 4;
	n4->link = n1;		//As it's a circular linked list, last node(n4)
						//points to first node(n1).

	last = n4;			//The last pointer points to n4(last node).

	printf("Enter the info of the node to be deleted: ");
	scanf("%d", &data);

	last = deletion(last, data);		//We return the last pointer as it's the only way of accessing the list, 
										//and if it's modified after this function call, we'll know the new position.
										//last pointer and the data of node to be deleted are passed as arguments.

	display(last);					//We pass last pointer to it, to access and display the list.

	return 0;						//Return 0 as main() returns an int value.
}

struct node *deletion(struct node *last, int data){		//Actual definition of our funtion.

	struct node *temporary;			//The pointer we will use to point to the node to be deleted so
									//the deleted node's space can be dynamically freed using this pointer.

	struct node *ptr;				//We will use this pointer to iterate through
									//the list to find the node to be deleted.

	//If the List is empty.
	
	if(last == NULL){				//Last pointing to NULL is the condition 
		printf("List is empty.");	//of an Empty circular linked list.
		return last;
	}

	//Deletion of only node i.e., the list contains only one node.

	if(last->link == last && last->info == data){	//First condition checks that the node points to itself as
													//its the condition if only a node is in the list.
													//The second condition checks if the info of only node matches
													//the info of the node to be deleted.

		temporary = last;			//we put the last node in the temporary pointer.

		last->link = NULL;			//we put the last node's address as NULL, so the last pointer now
									//points to NULL.

		free(temporary);			//Free the space allocated to the deleted node.

		return last;				//Return the last pointer to main().
	}

	//If the node to be deleted is the first node.

	if(last->link->info == data){		//First node equals the data of node to be deleted.

		temporary = last->link;			//Then put the first node address into the temporary pointer.

		last->link = temporary->link;	//Now the last node points to the second node.

		free(temporary);				//Free the dynamically llocated space of the deleted node using free().

		return last;					//Return the last pointer to main().
	}

	//Deletion of a node present in between the first and last nodes.

	ptr = last->link;					//To traverse the list, we assign the ptr pointer
										//the address of the first node of the list.

	while(ptr->link!=last){				//Till we reach the second last node.

		if(ptr->link->info == data){	//if the data of the node equals the info of node to be deleted.

			temporary = ptr->link;		//store the address of this node in temporary.

			ptr->link = temporary->link;	//now the current node(previous to the node to be deleted) points to the node
											//next to the node to be deleted.

			free(temporary);			//free the dynamically allocated space of the deleted node.

			return last;				//return last pointer to main().
		}
		ptr = ptr->link;				//Increment the pointer to the next node.
	}

	//Now that the ptr has reached the second last node of the list, there
	//is a possibility that the last node is the one to be deleted.

	if(last->info == data){				//If the data of last node is equal to the info
										//of node to be deleted.

		temporary = last;				//Put last node's address in temporary.

		ptr->link = last->link;			//now the second last node points to the first node
										//as it has become the new last node of the list.

		last = ptr;						//last pointer points to the new last node.

		free(temporary);				//We free the dynamically allocated space.

		return last;					//Return the last pointer to main().
	}

	printf("Node %d is not present in the list.\n", data);
	
	return last;						//If all fails and the node to be deleted is not present in the
										//list, then just return the last pointer.

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
