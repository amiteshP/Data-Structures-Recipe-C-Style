#include<stdio.h>
#include<stdlib.h>
struct Qnode{
	int key;
	struct Qnode* next;
};
struct Queue{
	struct Qnode *front,*rear;
};
struct Qnode *newnode(int k)
{
	struct Qnode *temp=(struct Qnode*)malloc(sizeof(struct Qnode));
	temp->key=k;
	temp->next=NULL;
	return temp;
}
struct Queue *createqueue()
{
	struct Queue *queue=(struct Queue*)malloc(sizeof(struct Queue));
	queue->front=queue->rear=NULL;
	return queue;
}
struct Queue *enqueue(struct Queue *queue,int k)
{
	struct Qnode *temp=newnode(k);
	if(queue->rear==NULL)
	{
		queue->front=queue->rear=temp;
		return;
	}
	queue->rear->next=temp;
	queue->rear=temp;
}
struct Qnode *dequeue(struct Queue *queue)
{
	if(queue->front==NULL)
	{
		return NULL;
	}
	struct Qnode * temp=queue->front;
	queue->front=queue->front->next;
	if(queue->front==NULL)
	queue->rear=NULL;
	return temp;
}
int main()
{
	struct Queue *q=createqueue();
	enqueue(q,10);
	enqueue(q,20);
	dequeue(q);
	dequeue(q);
	enqueue(q,30);enqueue(q,40);enqueue(q,50);
	struct Qnode *n=dequeue(q);
	if(n!=NULL)
	printf("deqeued item  from the queue is %d",n->key);
	return 0;
}
