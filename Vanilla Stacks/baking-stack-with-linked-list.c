//Program discusses the Push(inserting an element), Pop(deleting an element)
//and Displaying the top element and all the stack elements with the linked 
//list implementation of STACK.

#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *link;
};

struct node *top = NULL;

void display();

void push_element(int element);

int pop_element();

int peek_element();

bool underflow();

int main(){
    
	int choice;
	
    int element;
	
    while(1){
        
    printf("\n");    
    printf("Choose one of the options below to modify your stack!\n");
	printf("1. Push an element into the stack. \n");
	printf("2. Pop the top element from the stack. \n");
	printf("3. Take a peek at the top element of the stack. \n");
	printf("4. Display the complete stack. \n");
	printf("5. Exit program.\n");

	scanf("%d", &choice);

	switch(choice){
		case 1:		printf("\nEnter the element you wanna push into the stack: ");
					scanf("%d", &element);
					push_element(element);
                    printf("\n");
					break;

		case 2:		printf("\nThe deleted(popped) element: ");
					element = pop_element();
					if(element!=-1)printf("%d", element);
					printf("\n");
                    break;

		case 3:		printf("\nThe top element of the stack: ");
					element = peek_element();
					if(element!=-1)printf("%d", element);
					printf("\n");
                    break;

		case 4:		printf("\nThe stack elements: \n");
					if(element!=-1)display();
                    printf("\n");
                    break;
		
		case 5:		exit(1);
						
		default:	printf("\nEnter choices between 1-5[inclusive].\n");	
	}
    
    }
	return 0;
}

void push_element(int element){
	struct node *new_node;

	new_node = (struct node *)malloc(sizeof(struct node));

	 if(new_node == NULL){
	 	printf("\nStackOverflow: The stack is already full.\n");
	 	return;
	 }
	 new_node->info = element;
	 new_node->link = top;
	 top = new_node;
}

int pop_element(){
	struct node *temporary;
	int element;
	if(underflow()){
		printf("\n StackUnderflow: The stack is already empty.\n");
		return -1;
	}

	temporary = top;
	element = temporary->info;
	top = top->link;
	free(temporary);
	return element;
}

int peek_element(){
	if(underflow()){
		printf("\nStackUnderflow: The stack is already empty.\n");
		return -1;	
	}
	return top->info;
}

bool underflow(){
	if(top == NULL)
		return true;
	return false;
}

void display(){
	struct node *ptr;

	ptr = top;

	if(underflow()){
		printf("\nStackUnderflow: The stack is already empty.\n");
		return;
	}

	while(ptr!=NULL){
		printf("%d  ", ptr->info);
		ptr = ptr->link;
	}
	printf("\n");
}