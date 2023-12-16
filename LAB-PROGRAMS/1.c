//1.write a program to implement the singly nexted list with operations
#include<stdio.h>
#include<stdlib.h>

void create();
void InsertAtBegin();
void InsertAtEnd();
void InsertAtPosition();
void DeleteFirstNode();
void DeleteLastNode();
void DeleteAtPosition();
int length();
void traverse();

struct node 
{
	int data;
	struct node *next;
}*root=NULL;
//main Function
int main()
{
	printf("\n\n\t\t** Singly linked list implementation **\n\n");
	int ch;
	do
	{
		create();
		printf("Enter 1 to add  0 to exit : ");
		scanf("%d",&ch);
	}while(ch);
	printf("\n\nSingle edlist created Succesfully \n\n");
	traverse();
	
	while(1)
	{
		printf("1.insert at begin\n");
		printf("2.insert at end\n");
		printf("3.insert at position\n");
		printf("4.delete first node\n");
		printf("5.delete node at end\n");
		printf("6.delete node at position\n");
		printf("7.length\n");
		printf("8.traverse\n");
		printf("9.exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch (ch)
		{
		case 1:InsertAtBegin();
			break;
		case 2:InsertAtEnd();
			break;
		case 3:InsertAtPosition();
			break;
		case 4:DeleteFirstNode();
			break;
		case 5:DeleteLastNode();
			break;
		case 6:DeleteAtPosition();
			break;
		case 7:int x=length();
				if(x==0)
				{
					printf("\n\nNo Elements\n\n");
				}
				else
				{
					printf("\n\nSize = %d\n\n",x);
				}
			break;
		case 8:traverse();
			break;
		case 9:printf("\n\nSuccesfully completed\n\n");
			   exit(0);		
		default:
			printf("Invalid entry\n");
		}
		printf("\n\n");		
	}
}
//creating function
void create()
{
	struct node* new;
	new=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data :");
	scanf("%d",&new->data);
	new->next=NULL;
	if(root==NULL)
	{
		root=new;		
	}
	else
	{
		new->next=root;
		root=new;
	}
	printf("\n%d added succesfully\n",new->data);
}

//insert at begin function
void InsertAtBegin()
{
	struct node* new;
	new=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data :");
	scanf("%d",&new->data);
	new->next=NULL;
	if(root==NULL)
	{
		root=new;		
	}
	else
	{
		new->next=root;
		root=new;
	}
	printf("\n%d added succesfully\n",new->data);
}

void InsertAtEnd()
{
	struct node* new;
	new=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data :");
	scanf("%d",&new->data);
	new->next=NULL;
	if(root==NULL)
	{
		root=new;		
	}
	else
	{
		struct node *p=root;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=new;
	}
	printf("\n%d added succesfully\n",new->data);

}

void InsertAtPosition()
{
	struct node* new;
	new=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data :");
	scanf("%d",&new->data);
	new->next=NULL;
	if(root==NULL)
	{
		root=new;		
	}
	else
	{
		int pos,i;
		struct node *p=root;
		printf("Enter the position");
		scanf("%d",&pos);
		if(pos==1)
		{
			new->next=root;
			root=new;
			printf("\n\n%d added succesfully\n\n",new->data);
		}
		else if(pos<=length())
		{
			
			for(i=1;i<pos-1;i++)
			{
				p=p->next;
			}
			new->next=p->next;
			p->next=new;
			printf("\n\n%d added succesfully\n\n",new->data);

		}
		else
		{
			printf("\n\nInvalid Position\n\n");
		}
	}
	

}

void DeleteFirstNode()
{
	if(root==NULL)
	{
		printf("\n\nNo Elements\n\n");
	}
	else
	{
		printf("\n\n%d is deleted\n\n",root->data);
		root=root->next;
	}

}
void DeleteLastNode()
{
	if(root==NULL)
	{
		printf("\n\nNo Elements\n\n");
	}
	else if(root->next==NULL)
	{
		printf("\n\n%d is deleted\n\n",root->data);
		root=NULL;
	}
	else
	{
		struct node *p=root,*ptr;
		while(p->next!=NULL)
		{
			ptr=p;
			p=p->next;
		}
		ptr->next=NULL;
		printf("\n\n%d is deleted\n\n",p->data);
		
	}

}

void DeleteAtPosition()
{	
	if(root==NULL)
	{
		printf("\n\nNo Elements\n\n");
	}
	else 
	{
		struct node *p,*q;
		int pos,i;
		printf("Enter the position");
		scanf("%d",&pos);
		if(pos>length())
		{
			printf("\n\nInvalid Position\n\n");
		}
		else if(pos==1)
		{
			p=root;
			root=p->next;
			p->next=NULL;
			free(p);
		}
		else
		{
			int i;
			p=root;
			for(i=1;i<pos-1;i++)
			{
				p=p->next;
			}
			q=p->next;
			p->next=q->next;
			q->next=NULL;
			printf("\n\n%d is deleted\n\n",q->data);
			free(q);
		}		
	}
}

int length()
{
	int count=0;
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		struct node *p=root;
		while(p!=NULL)
		{
			count++;
			p=p->next;
		}
		return count;
	}
}
void traverse()
{
	printf("\n\n");
	if(root==NULL)
	{
		printf("\nNo elements\n");
	}
	else
	{
		struct node *p=root;
		while(p!=NULL)
		{
			printf("%d-->",p->data);
			p=p->next;
		}
	}
	printf("\n\n");
}