//Program discusses about how to traverse or display through a Circular Linked List

#include<stdio.h>		//Input/Output library for Standard functions. 

void display(struct node *);	//The declaration of our function so the program knows
								//it will be used below.


struct node{				//We define the structure of the node.

	int info;				//Data part of the node.

	struct node *link;		//The link part of the node.
};

int main(){						
	struct node *last = NULL;		//In circular linked list we have a "last pointer", which
									//points to the last node of the list. This marks the end.


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

	display(last);					//last pointer is passed as method argument.
	
	return 0;						//Return 0 as main() retunrs an Int value.
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