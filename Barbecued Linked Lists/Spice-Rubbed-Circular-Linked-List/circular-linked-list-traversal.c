#include<stdio.h>

void display(struct node *);

struct node{
	int info;
	struct node *link;
};

int main(){
	struct node *last = NULL;

	struct node n1, n2, n3, n4;

	n1.info = 1;
	n1.link = &n2;
	n2.info = 2;
	n2.link = &n3;
	n3.info = 3;
	n3.link = &n4;
	n4.info = 4;
	n4.link = &n1;

	last = &n4;

	display(last);
	return 0;
}

void display(struct node *last){
	struct node *ptr;
	if(last == NULL){
		printf("The list is empty.");
		return;
	}
	ptr = last->link;
	do{
		printf("%d  ", ptr->info);
		ptr = ptr->link;
	}
	while(ptr != last->link);
}