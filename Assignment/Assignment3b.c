#include<stdio.h>
#include<stdlib.h>
#define size 5
struct queue
{
	int array[size];
	int front, rear;
	char full;
};
int enqueue(struct queue * myqueue, int elem)
{
	if(myqueue -> full)
	{
		printf("Queue is full");
		return -1;

	}
    myqueue->array[myqueue->rear]=elem;
    myqueue->rear= ++myqueue->rear % size;
    if(myqueue->rear == myqueue-> front)
    myqueue->full =1;

}
int dequeue(struct queue *myqueue, int *status)
{
    if(myqueue->front == myqueue-> rear && !myqueue->full)
    {
        printf("Queue is empty");
        *status = 0;
        return -1;
    }
    *status =1;
    if(myqueue->full)   myqueue->full = 0;
    int val= myqueue->array[myqueue->front];
    myqueue->front=(myqueue->front +1) % size;
    return val;
}
void init(struct queue *myqueue)
{
	myqueue -> front = 0;
	myqueue -> rear = 0;
	myqueue -> full = 0;
}
int main()
{
	int elem;
	struct queue myqueue;
	init(&myqueue);
	int choice;
	int val, status;
	while(-100)
	{
		printf("\nEnter:\n\t1 - to Insert to Queue\n\t2 - to Delete from Queue\n\t0 - to Exit: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Please enter the element: ");
				scanf("%d", &elem);
				enqueue(&myqueue, elem);
				break;
			case 2:
				val = dequeue(&myqueue, &status);
				if(status  == 1)
				{
					printf("Removed element is %d: \n", val);
				}
				break;
			case 0: exit(0);
		}
	}
	printf("\n");

}
