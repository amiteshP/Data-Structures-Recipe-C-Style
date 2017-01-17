//The program discusses how to insert a particular element at the beginning of a Linked List.
-
#include<stdio.h>					//For Input/Output functions used from standard library.
#include<stdlib.h>					//For functions used for Dynamical Allocation of memory.

struct node *insert_at_beginning(struct node *start, int data);			//Declare the function here so 
																		//the program knows it's gonna be used.

void display(struct node *start);	//A function used to display the list, can be found in file
									//singly-linked-list-traversal.c in the italian linked list flavour

struct node{						//First we define how a node in
	int info;						// the list will look like with  
	struct node *link;				//the help of a Structure.
};

int main(){

	struct node *start = NULL;		//We define the first node to be
									//the "start" node, which is a pointer
									//to the first node having Data(info).
	
	int data;						//Variable we'll use to hold the data to insert in the new node.
	struct node n1, n2, n3;			//The three nodes of our already existing list.
	start = &n1;					//Start holds the address of first node.
	n1.info = 1;				
	n1.link = &n2;					//The first node points to the second node.
	n2.info = 2;
	n2.link = &n3;					//The second node points to the third node.
	n3.info = 3;
	n3.link = NULL;					//The third node points to NULL, indicating end of list.

	printf("Enter the element you wanna enter at the beginning of the Linked List: ");
	scanf("%d", &data);
	start = insert_at_beginning(start, data);		//Our function returns start, so if it's position is changed,
													//we can have the new position, as it's the pnly way of
													//accessing the list.
	display(start);					//To display the newly modified list

	return 0;
}

struct node *insert_at_beginning(struct node *start, int data){		//Actual function definition

	struct node *new_node;											//Pointer to the new node we are adding
	
	new_node = (struct node *)malloc(sizeof(struct node));		//Allocating memory to the new node(with malloc), of size equal to of a node in our structure, 
																//and returning the pointer to it, to the new_node pointer.	
	
	new_node->info = data;					//Adding the data to the new node

	new_node->link = start;					//Now this new_node should point to the second node(which was previously first),
											//and it's address is stored in start
	start = new_node;						//start pointer should now point to the new_node(as it's the first), this step is 
											//performed later as we want the address in start for the previous step.
	return start;							//Finally we return start pointer.				
}

void display(struct node *start){	//This is the definition of display()
	struct node *ptr;
	
	//Here, we know the list isn't empty, so no need of checking it for that condition.

	ptr = start;					
	printf("List is: \n");
	while(ptr != NULL){				//This loop goes on till the last node is encountered
		printf("%d  ", ptr->info);	//after which it points to NULL, and the loop breaks.
		ptr = ptr->link;
	}
}









