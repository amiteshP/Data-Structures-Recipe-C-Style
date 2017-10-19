//Program discusses how to delete a node in a single linked list.

#include<stdio.h>					//For Input/Output functions used from standard library.
#include<stdlib.h>					//For functions used for Dynamical Allocation of memory.

struct node *delete_node(struct node *start, int data);			//Function declaration so program knows that it'll be used in the code.

void display(struct node *start);	//A function used to display the list, can be found in file
									//singly-linked-list-traversal.c in the Italian Linked List flavour

struct node{						//First we define how a node in
	int info;						// the list will look like with  
	struct node *link;				//the help of a Structure.
};

int main(){

	struct node *start = NULL;		//We define the first node to be
									//the "start" node, which is a pointer
									//to the first node having Data(info).
	
	int data;						//Variable we'll use to hold the data regarding the node which we'll delete.

	//Now we dynamically allocate memory for three nodes of our list,
	//so we can illustrate how to release the memory space using 'free'

	struct node *n1;		//Pointer to first node.
	n1 = (struct node *)malloc(sizeof(struct node));		//First node.
	struct node *n2;		//Pointer to second node.
	n2 = (struct node *)malloc(sizeof(struct node));		//Second node.
	struct node *n3;		//Pointer to third node.
	n3 = (struct node *)malloc(sizeof(struct node));		//Third node.

	
	
	start = n1;					//Start holds the address of first node.
	n1->info = 1;				
	n1->link = n2;					//The first node pointer points to the second node.
	n2->info = 2;
	n2->link = n3;					//The second node pointer to the third node.
	n3->info = 3;
	n3->link = NULL;					//The third node pointer to NULL, indicating end of list.

	printf("Enter the data of node which you wanna delete: ");
	scanf("%d", &data);

	start = delete_node(start, data);		//Our function returns start, so if it's position is changed,
											//we can have the new position, as it's the only way of
											//accessing the list. The data of the node to be deletd
											//is passed as argument.
	
	display(start);				//To display the newly modified list
}

struct node *delete_node(struct node *start, int data){		//Actual Function definition
	
	struct node *temporary;			//This pointer will be used to point to the 
									//node we are deleleting, so we can free
									//the memory space taken by the deleted node.

	struct node *ptr;				//Used to hold the pointer position of the node
									//before the node we want to delete.

	if(start->info == data){		//Here we check if the node to 
									//be deleted is the first one.

		temporary = start;			//If true, we store the first node's 
									//address in the temporary pointer.
									//So we can free it later.

		start = start->link;		//Link the Start to the second node of the list,
									//which is now the first node(or to null incase
									//deleted node is the only one in list.
		
		free(temporary);			//Now we free the dynamic space which was allocated
									//to the deleted node.

		return start;				//Finally we return the start pointer of the newly
									//modified list.
	}

	ptr = start;				//If it's not the first node, then it can be in between,
								//or maybe the last node.

	while(ptr->link != NULL){			//Loop through till the last node is reached.

		if(ptr->link->info == data){		//If the current node's next node is the node
											//to be deleted.
			
			temporary = ptr->link;			//Then, now temporary points to the node to be deleted.

			ptr->link = temporary->link;	//Current node points to the node which is after the
											//node to be deleted.

			free(temporary);			//Free the dynamic space of the node which we deleted.

			return start;				//Return the start pointer of the newly modified list.
		}

		ptr = ptr->link;		//Increment the pointer to the next node.
	}
	
	printf("The node having data %d is not present in the list.\n", data);
	
	return start;			//In any case, return the start pointer.
}

void display(struct node *start){	//This is the definition of display()
	
	struct node *ptr;
	
	if(start == NULL){				//First check if the list is empty
		printf("List is empty.");	//by comparing the start pointer with NULL(empty)
		return;
	}

	ptr = start;					
	printf("List is: \n");
	while(ptr != NULL){				//This loop goes on till the last node is encountered
		printf("%d  ", ptr->info);	//after which it points to NULL, and the loop breaks.
		ptr = ptr->link;
	}
}









