//Program discusses how to insert a new node at a specified position in the Liked-List

#include<stdio.h>					//For Input/Output functions used from standard library.
#include<stdlib.h>					//For functions used for Dynamical Allocation of memory.

struct node *insert_at_pos(struct node *start, int data, int pos);		//Function declaration so program knows that it'll be used in the code.

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
	
	int data;						//Variable we'll use to hold the data to insert in the new node.

	int pos;						//Variable to hold the position at which the new node is to be inserted.

	struct node n1, n2, n3;			//The three nodes of our already existing list.
	start = &n1;					//Start holds the address of first node.
	n1.info = 1;				
	n1.link = &n2;					//The first node points to the second node.
	n2.info = 2;
	n2.link = &n3;					//The second node points to the third node.
	n3.info = 3;
	n3.link = NULL;					//The third node points to NULL, indicating end of list.
	
	printf("Enter the element you wanna enter at the specified position of the Linked List: ");
	scanf("%d", &data);

	printf("\nEnter the position at which you wanna insert the new node: ");
	scanf("%d", &pos);

	start = insert_at_pos(start, data, pos);		//Our function returns start, so if it's position is changed,
													//we can have the new position, as it's the only way of
													//accessing the list. The data of new node and the position to insert
													//is passed as arguments.

	display(start);					//To display the newly modified list

	return 0;
}

struct node *insert_at_pos(struct node *start, int data, int pos){		//Actual function definition.

	struct node *new_node;							//Pointer to the new node we are adding.

	struct node *ptr;								//To access the pointer to the node before which we have to insert new node.

	int m;		//Variable declared so it can be used for looping(for-loop)purpose below.

	new_node = (struct node*)malloc(sizeof(struct node));		//Allocating memory to the new node(with malloc), of size equal to of a  
																//node in our structure, and returning the pointer to it, to the new_node pointer.
    
    new_node->info = data;							//Adding the data to the new node.
    
    if(pos==1){										//If the position is at the beginning of the list.

        new_node->link = start;						//Now this new_node should point to the second node(which was previously first),
													//and it's address is stored in start.
       
        start = new_node;							//start pointer should now point to the new_node(as it's the first), this step is 
													//performed later as we want the address in start for the previous step.
        
        return start;								//Finally we return start pointer.
    }

    ptr = start;							//Now, we want to find the position at which we have to add the new node
											//in the list, the only way is through accessing the whole list from start.								

    for(m=1; m<pos-1 && pos!=NULL; m++){		//We loop through the list till we get to the position or to the end of list(NULL reached).
	
	     ptr = ptr->link;						//Increment the pointer to the next node.

	}					
    
    if(ptr==NULL)							//If we reach to the end of the list.
        printf("There are less than %d elements in the list!\n", pos);

    else{									//We find the position at which we have to insert.

        new_node->link = ptr->link;			//Now, we assign the pointer to the next node in the previous list,
											//at this position, to the new_node, as now it'll point to it.			
  	
  		ptr->link = new_node;				//The node after which we have added the new_node gets it's link pointed
											//to the new node.

    }
    return start;							//Return the start pointer.
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







