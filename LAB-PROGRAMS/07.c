//7.write a program to implement the Queue using linked list
#include<stdio.h>
#include<stdlib.h>

void enqueue();
void dequeue();
void display();


struct node 
{
	int data;
	struct node *link;
}*root=NULL;
//main Function
int main()
{
	printf("\n\n**Queue Implementation**\n\n");
    int ch;
    while(1)
    {
        printf("1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.display\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:enqueue();
                break;
            case 2:dequeue();
                break;
            case 3:display();
                break;
            case 4:exit(0);
            default:printf("\nInvalid Entry\n");

        }
        printf("\n\n");
    }
}

//insert at begin function
void enqueue()
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
		struct node *p=root;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=new;
	}
	printf("\n%d added succesfully\n",new->data);
}


void dequeue()
{
	if(root==NULL)
	{
		printf("\n\nNo Elements\n\n");
	}
	else
	{
		printf("\n\n%d is deleted\n\n",root->data);
		root=root->link;
	}
}


void display()
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
			p=p->link;
		}
	}
	printf("\n\n");
}
