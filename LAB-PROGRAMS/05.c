/*
    5.write a program to implement the stack using linked list
*/
#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void display();
void create();


struct node 
{
	int data;
	struct node *link;
}*root=NULL;
//main Function
int main()
{
	printf("\n\n\t\t** Stack using Singly linked list implementation **\n\n");
	int ch,l;
	do
	{
		create();
		printf("Enter 1 to add 0 to stop :");
		scanf("%d",&ch);
	}while(ch);

	printf("\nStack is created\n");
	display();

	while(1)
	{
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.dispaly\n");
		printf("4.exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);

		switch (ch)
		{
		case 1:push();
			break;
		case 2:pop();
			break;
		case 3:display();
			break;
		case 4:exit(0);	
		default:
			printf("Invalid entry\n");
		}
		printf("\n\n");
		
	}
}
//Creation functon
void create()
{
	struct node* new;
	new=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data :");
	scanf("%d",&new->data);
	new->link=NULL;
	if(root==NULL)
	{
		root=new;		
	}
	else
	{
		new->link=root;
		root=new;
	}
	printf("\n%d pushed succesfully\n",new->data);
}

//insert at begin function
void push()
{
	struct node* new;
	new=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data :");
	scanf("%d",&new->data);
	new->link=NULL;
	if(root==NULL)
	{
		root=new;		
	}
	else
	{
		new->link=root;
		root=new;
	}
	printf("\n%d pushed succesfully\n",new->data);
}


void pop()
{
	if(root==NULL)
	{
		printf("\n\nStack is Under flow\n\n");
	}
	else
	{
		printf("\n\n%d is poped\n\n",root->data);
		root=root->link;
	}

}



void display()
{
	printf("\n\n");
	if(root==NULL)
	{
		printf("\nStack is Under flow\n");
	}
	else
	{
		struct node *p=root;
		while(p!=NULL)
		{
			printf("%d-->",p->data);
			p=p->link;
		}
	}
	printf("\n\n");
}
