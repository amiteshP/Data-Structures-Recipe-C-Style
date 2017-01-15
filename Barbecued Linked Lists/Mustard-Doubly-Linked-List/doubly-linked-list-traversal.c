//The program discusses how to display through a set of elements of a Doubly-Linked List

#include<stdio.h>					//For standard Input/Output functions used

void display(struct node *start);	//we declare our function display here
									//so the program knows we're gonna use it.

struct node{		
	struct node *prev;				//The structure of a doubly linked list
	int info;						//has two pointers, one for previous node
	struct node *next;				//and the other for next node.
};

int main(){

	struct node *start = NULL;		//We define the first node to be
									//the "start" node, which is a pointer
									//to the first node having Data(info).

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

	display(start);					//Now, we call the display function, with the start
									//pointer passed as argument.
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