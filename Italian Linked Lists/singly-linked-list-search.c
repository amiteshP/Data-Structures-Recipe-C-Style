#include<stdio.h>					//For standard Input/Output functions used		

int search(struct node *start, int data);	//We declare our function here
											//so the program knows we're gonna use it.

struct node{						//First we define how a node in
	int info;						// the list will look like with 
	struct node *link;				//the help of a Structure.
};	

int main(){
	struct node *start = NULL;		//We define the first node to be
									//the "start" node, which is a pointer
									//to the first node having Data(info).

	int pos;						//This will store our position
	struct node n1, n2, n3, n4;		//We declare four nodes for our program.

	start = &n1;					//start, the pointer we defined earlier
	n1.info = 1;					//points to the first node n1.
	n1.link = &n2;					//n1 points to n2.
	n2.info = 2;					
	n2.link = &n3;					//n2 points to n3.
	n3.info = 3;
	n3.link = &n4;					//n3 points to n4.
	n4.info = 4;
	n4.link = NULL;					//n4, the last node, points to NULL, to indicate
									//end of the Linked List.

	pos = search(start, 3);			//Now, we call the search function, with the start
									//pointer and the element we wanna search

	if(pos==-1)printf("Element not present in the list.");		//Finally we check the returned value of pos
	else printf("Element is present in the %d position.", pos);

}

int search(struct node *start, int data){	//Function definition of Search function
	struct node *ptr;
	int pos = -1;					//If element not found then -1 is the default position
	int count = 0;
	if(start == NULL){				//First check if the list is empty
		printf("List is empty.");	//by comparing the start pointer with NULL(empty)
		return -1;					//-1 as the function returns an int
	}
	ptr = start;
	while(ptr!=NULL){				//If not, then we continue to search list
		if(ptr->info == data){		//If match found:
			pos = count;			//put the current count of node in the positiona and break.
			break;
		}
		count++;					//Else, keep searching and counting through the elements
		ptr = ptr->link;			//Loops through the list till the last node(NULL) occurs
	}
	return pos;						//Return the position
}










