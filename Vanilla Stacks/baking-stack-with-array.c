//Program discusses the Push(inserting an element), Pop(deleting an element)
//and Displaying the top element and all the stack elements with the array 
//implementation of STACK.

#include<stdio.h>
#include<stdlib.h>

#define size 10

int stack_array[size];

int top = -1;

void display();

void push_element(int element);

int pop_element();

int peek_element();

bool underflow();

bool overflow();

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
	 if(overflow()){
	 	printf("\nStackOverflow: The stack is already full.\n");
	 	return;
	 }
	 top = top + 1;
	 stack_array[top] = element;
}

int pop_element(){
	int deleted;
	if(underflow()){
		printf("\n StackUnderflow: The stack is already empty.\n");
		return -1;
	}
	deleted = stack_array[top];
	top = top - 1;
	return deleted;
}

int peek_element(){
	if(underflow()){
		printf("\nStackUnderflow: The stack is already empty.\n");
		return -1;	
	}
	return stack_array[top];
}

bool underflow(){
	if(top == -1)
		return true;
	return false;
}

bool overflow(){
	if(top == size-1)
		return true;
	return false;
}

void display(){
	int i;
	if(underflow()){
		printf("\nStackUnderflow: The stack is already empty.\n");
		return;
	}
	for(i=top; i>=0; i--){
		printf("%d\n", stack_array[i]);
	}
	printf("\n");
}