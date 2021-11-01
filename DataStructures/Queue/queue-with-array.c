//Q. Write a C program to implement Queue (Insert, Delete, Display) using array.
//First in first out
#include<stdio.h>
int enqueue(int arr[],int front,int rear,int size)
{
	if((rear+1)%size==front)
		{
			printf("Queue is full\n");
			return 0;
		}
	else if(front!=-1 && rear==size-1)
	{
		int temp;
		printf("Enter element\n");
		scanf("%d",&temp);
		rear=(rear+1)%size;
		arr[rear]=temp;
		return 1;
	}
	else
	{
	int temp;
	printf("Enter element\n");
	scanf("%d",&temp);
	rear=(rear+1)%size;
	arr[rear]=temp;
	return 1;
	}
}
int dequeue(int arr[],int front,int rear,int size)
{
	if(front==-1)
	{
		printf("Queue is empty\n");
		return 0;
	}
	else if(front==rear)			// if only 1 element in queue
	{
		printf("%d is dequeued\n",arr[front]);
		front=rear=-1;
		return 3;
	}
	else
	{
	printf("%d is dequeued\n",arr[front]);
	return 1;
	}
}
void display(int arr[],int front,int rear,int size)
{
	if(front==-1)
	printf("Queue is empty\n");
	else if(front==rear && (front!=-1 && rear!=-1))
	{
		printf("%d ",arr[front]);
	}
	else
	{
		int temp=front;
		while(temp!=rear)
			{
				printf("%d ",arr[temp]);
				temp=(temp+1)%size;
			}
		printf("%d\n",arr[temp]);
	}
}
int main()
{
	int size,n;
	printf("Enter size of array\n");
	scanf("%d",&size);
	int arr[size];
	int a;
	int front=-1;
	int rear=-1;
	while(1)
	{
		printf("-----------------\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit---------------------\n");
		scanf("%d",&n);
		switch (n)
			{
				case 1:
					{
						int x=enqueue(arr,front,rear,size);
						if(x==1)
						{
							rear=(rear+1)%size;
							if(front==-1)
							{
								front=0;
							}
						}
						break;
					}
				case 2:
				{
					int x=dequeue(arr,front,rear,size);
					if(x==1)
					front=(front+1)%size;
					else if(x==3)
					front=rear=-1;	//null queue
					break;
				}
				case 3:
				{
					display(arr,front,rear,size);
					break;
				}
				case 4: exit(1);
			}
	}
}
