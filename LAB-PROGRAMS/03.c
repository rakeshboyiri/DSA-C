//1.write a program to implement the circular linked list with operations
#include<stdio.h>
#include<stdlib.h>

void InsertAtBegin();
void InsertAtEnd();
void InsertAtPosition();
void DeleteFirstNode();
void DeleteLastNode();
void DeleteAtPosition();
void create();
int length();
void traverse();


struct node 
{
	int data;
	struct node *link;
}*tail=NULL,*new;
//main Function
int main()
{
	int x;
	printf("\n\n\t\t** circular linked list implementation **\n\n");
	int ch;
	do
	{
		create();
		printf("Enter 1 to add 0 to stop :");
		scanf("%d",&ch);
	}while(ch);
	printf("\n\n\t\t** circular linked list created **\n\n");
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
		case 6: DeleteAtPosition();
			break;
		case 7:x=length();
			if(x==0)
			{
				printf("\n No elements\n");
			}
			else
			{
				printf("\nsize=%d",x);
			}
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
//Create
void create()
{
	new=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data :");
	scanf("%d",&new->data);
	new->link=NULL;
	if(tail==NULL)
	{
		tail=new;
        tail->link=new;		
	}
	else
	{		
		new->link=tail->link;
		tail->link=new;
	}
	printf("\n%d added succesfully\n",new->data);

}
//insert at begin function
void InsertAtBegin()
{
	new=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data :");
	scanf("%d",&new->data);
	new->link=NULL;
	if(tail==NULL)
	{
		tail=new;
        tail->link=new;		
	}
	else
	{		
		new->link=tail->link;
		tail->link=new;
	}
	printf("\n%d added succesfully\n",new->data);

}
void InsertAtEnd()
{	
	struct node* new;
	new=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data :");
	scanf("%d",&new->data);
	new->link=NULL;
	if(tail==NULL)
	{
		tail=new;
        tail->link=new;		
	}
	else
	{
		new->link=tail->link;
        tail->link=new;
        tail=new;	
	}
	printf("\n%d added succesfully\n",new->data);

}

void InsertAtPosition()
{
	struct node* new,*p;
	new=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data :");
	scanf("%d",&new->data);
	new->link=NULL;
	if(tail==NULL)
	{
		tail=new;	
		tail->link=new;	
	}
	else
	{
		int pos,i;
		p=tail->link;
		printf("Enter the position");
		scanf("%d",&pos);
		if(pos==1)
		{
			new->link=tail->link;
			tail->link=new;
			
		}
		else if(pos<=length())
		{			
			for(i=1;i<pos-1;i++)
			{
				p=p->link;
			}
			new->link=p->link;
			p->link=new;
		}
		else if(pos==length())
		{
			new->link=tail->link;
        	tail->link=new;
        	tail=new;
		}
		else
		{
			printf("\n\nInvalid Position\n\n");
			return;

		}
	}
	printf("\n\n%d added succesfully\n\n",new->data);
	

}

void DeleteFirstNode()
{
	
	if(tail==NULL)
	{
		printf("\n\nNo Elements\n\n");
		return;

	}
	struct node*p=tail->link;
	if(p->link==tail->link)
	{
		printf("\n\n%d is deleted\n\n",p->data);
		tail=NULL;
		free(p);
		return;
		
	}
	
	
		printf("\n\n%d is deleted \n\n",p->data);
		tail->link=p->link;
		free(p);

}

void DeleteLastNode()
{
	
	if(tail==NULL)
	{
		printf("\n\nNo Elements\n\n");
		return;
	}	
	struct node*p=tail->link;
	if(tail->link==p->link)
	{
		printf("\n\n%d is deleted\n\n",tail->data);
		tail=NULL;
		return;
	}	
		struct node *ptr;
		while(p->link!=tail->link)
		{
			ptr=p;
			p=p->link;
		}
		ptr->link=tail->link;
		tail=ptr;
		printf("\n\n%d is deleted\n\n",p->data);
		free(p);
}

void DeleteAtPosition()
{	
	if(tail==NULL)
	{
		printf("\n\nNo Elements\n\n");
		return;
	}

	struct node *p,*q;
	int pos,i;
	printf("Enter the position");
	scanf("%d",&pos);
	if(pos>length())
	{
		printf("\n\nInvalid Position\n\n");
		return;
	}
	
	if(pos==1)
	{
		DeleteFirstNode();
		return;
	}
	if(pos==length())
	{
		DeleteLastNode();
		return;
	}
	{
		int i;
		p=tail->link;
		for(i=1;i<pos-1;i++)
		{
			p=p->link;
		}
		q=p->link;
		p->link=q->link;
		printf("\n\n%d is deleted\n\n",q->data);
		free(q);
	}		
}

int length()
{
	struct node* p;
	int count=1;
	if(tail==NULL)
	{
		return 0;
	}
	else
	{
		p=tail->link;
		while(p->link!=tail->link)
		{
			count++;
			p=p->link;
		}
		return count;
	}
}

void traverse()
{
	struct node* p;
	printf("\n\n");
	if(tail==NULL)
	{
		printf("\nNo elements\n");
	}
	else
	{
		p=tail->link;
		while(p->link!=tail->link)
		{
			printf("%d-->",p->data);
			p=p->link;
		}
        printf("%d-->",p->data);
	}
	printf("\n\n");
}
