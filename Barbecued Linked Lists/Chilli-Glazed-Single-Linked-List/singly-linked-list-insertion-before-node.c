//Program discusses how to insert a new node BEFORE a specified node in the Linked-List

#include<stdio.h>					//For Input/Output functions used from standard library.
#include<stdlib.h>					//For functions used for Dynamical Allocation of memory.

struct node *insert_before(struct node *start, int data, int item); //Function declaration: so program knows that it'll be used in the code.

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

	int item;						//Variable we'll use to hold the value of node before which the new node is to be inserted.

	struct node n1, n2, n3;			//The three nodes of our already existing list.
	start = &n1;					//Start holds the address of first node.
	n1.info = 1;				
	n1.link = &n2;					//The first node points to the second node.
	n2.info = 2;
	n2.link = &n3;					//The second node points to the third node.
	n3.info = 3;
	n3.link = NULL;					//The third node points to NULL, indicating end of list.

	printf("Enter the data of the new node: ");
	scanf("%d", &data);
	printf("\nEnter the node value before which new node is to be inserted: ");
	scanf("%d", &item);
	start = insert_before(start, data, item);	//the function returns start, as if it's position is modified during the function
												//execution, we will know the new position as it's the only way to access the list.
												//The data to be inserted and the node-value before which to insert is passed as arguments.

	display(start);					//To display the newly modified list
	return 0;
}

struct node *insert_before(struct node *start, int data, int item){	//Actual function definition.
	
	struct node *new_node;						//Pointer to the new node we're adding.

	struct node *ptr;							//To access the pointer to the node before which we have to insert new node.

	if(start==NULL){							//If the list is Empty. This is checked so the next if-block is executed correctly.
		printf("List is Empty.\n");
		return start;
	}
	if(item == start->info){					//If item before which we wish to insert new_node is the fist node in the list.

		new_node = (struct node *)malloc(sizeof(struct node));		//Allocating memory to the new node(with malloc), of size equal to of a  
																	//node in our structure, and returning the pointer to it, to the new_node pointer.	
	
		new_node->info = data;					//Adding the data to the new node

		new_node->link = start;					//Now this new_node should point to the second node(which was previously first),
												//and it's address is stored in start.

		start = new_node;						//start pointer should now point to the new_node(as it's the first), this step is 
												//performed later as we want the address in start for the previous step.
		
		return start;							//Finally we return start pointer.
	}

	ptr = start;							//Now, we want to find the element before which we have to add the new node
											//in the list, the only way is through accessing the whole list from start.								

	while(ptr->link!=NULL){						//Loop through till the end of list(next node points to NULL)

		if(ptr->link->info == item){				//If the node before which new node is to be added is found.

			new_node = (struct node *)malloc(sizeof(struct node));	//Allocate the new_node memory equal to structure of node,
																	//return pointer to the new_node pointer declared above.
			new_node->info = data;				//Insert data in the new_node.

			new_node->link = ptr->link;			//Now, we assign the pointer to the next node in the previous list
												//at this position, to the new_node, as now it'll point to it.

			ptr->link = new_node;				//The node after which we have added the new_node gets it's link pointed
												//to the new node.

			return start;						//Return the start pointer.
		}
		ptr = ptr->link;					//If not found, then increment the pointer to the next node.
	}
	printf("The item before which new node is to be entered is not present in the list.\n");
	
	return start;		//Return the start pointer even if the node before which new node is to be enetered is not found.
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








