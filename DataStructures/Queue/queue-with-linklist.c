//Queue: first in first out
//new address lera hai bss...
#include<stdio.h>
typedef struct node{
	int data;
	struct node* next;
}nodetype;
nodetype* insert(nodetype*);
nodetype* delete(nodetype*);
void display(nodetype*);
int main()
{
	int i;
	nodetype *front=NULL,*rear=NULL;
	do
	{
		printf("============================================================\n1.insert\n2.delete\n3.display\n4.Quit\n--------------\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				rear=insert(rear);
				if(front==NULL)
				front=rear;
				break;
			case 2:
				front=delete(front);
				if(front==NULL)
				rear=NULL;
				break;
			case 3:
				display(front);
				break;
		}
	}while(i<4);
}
nodetype* insert(nodetype* rear)
{
	int n;
	nodetype *p=NULL;
	p=(nodetype*)malloc(sizeof(nodetype));
	if(p!=NULL)
	{
		printf("Enter the element\n");
		scanf("%d",&n);
		p->data=n;
		if(rear==NULL)	//starting condition...
		{
			rear=p;		//new address lera hai bss...
		}
		else
		{
			rear->next=p;  //connecting address to previous node...(p has new address every time by malloc) and *****rear still pointing to last address*****
			rear=p;			// new address lera hai bss... *****now rear is pointing to current address*****
		}
		rear->next=NULL; 		//eg: rear pointing to 10a (so as p) so, rear->next i.e 10a's next which was garbage is turned into null
								//passing null to next node...
	}
	return rear;
}
nodetype* delete(nodetype* front)
{
	nodetype *temp=front;
	if(temp==NULL)
	{
		printf("No element is present\n");
	}
	else
	{
		printf("Element deleted is : %d\n",temp->data);
		front=front->next;
		free(temp);
	}
	return front;
}
void display(nodetype* front)
{
	if(front==NULL)
	printf("No element left\n");
	else
	{
		while(front!=NULL)
		{
			printf("%d ",front->data);
			front=front->next;
		}
	}
}


