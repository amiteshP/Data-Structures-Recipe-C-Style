//Program discusses about how to insert an element at the beginning of a Circular linked list.

#include<stdio.h>		//Library for standard Input/Output Functions.

#include<stdlib.h>		//Standard library for dynamically memory allocations.

struct node *insert_at_beginning(struct node *last, int data);	//Declaration of our funtion so the program
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

	int data;						//our variable to hold the data of the new_node to be inserted
									//in the beginning.

	struct node n1, n2, n3, n4;		//Four nodes of our List.

	n1.info = 1;
	n1.link = &n2;					//n1 node points to n2.
	n2.info = 2;
	n2.link = &n3;					//n2 node points to n3.
	n3.info = 3;
	n3.link = &n4;					//n3 node points to n4.
	n4.info = 4;
	n4.link = &n1;					//And then, given the circular nature of the
									//list, n4 again points to n1.

	last = &n4;						//The last pointer points to n4(lat node).


	printf("Enter the data value to be entered in the new node: ");
	scanf("%d", &data);

	last = insert_at_beginning(last, data);		//We return the last pointer as it's the only way of accessing the list, 
												//and if it's modified after this function application, we'll know the new position.
												//last pointer and the data of new_node are passed as arguments.

	display(last);					//We pass last pointer to it, to access and display the list.

	return 0;						//Return 0 as main() returns an int value.
}

struct node *insert_at_beginning(struct node *last, int data){		//Actual definition of our funtion.

	struct node *new_node;				//The pointer to our new_node.

	new_node = (struct node *)malloc(sizeof(struct node));		//We allocate memory equal to that of node, and return pointer
																//to the new_node pointer which is the pointer to the new_node to be inserted.

	new_node->info = data;				//We insert the data into our new_node.

	new_node->link = last->link;		//Now new_node(which is now the first node), points
										//to the previous first node(now second node)of the list.
	
	last->link = new_node;				//The last pointer which points to the beginning of the list
										//now points to the new first node.

	return last;						//The last pointer is returned back to main().
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








