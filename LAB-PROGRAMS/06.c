//6.write a program to implement the Queue using array

#include<stdio.h>
#include<stdlib.h>

#define SIZE 5
int que[SIZE];
int front=0,rear=0;

void enqueue();
void dequeue();
void display();

void main()
{
    printf("\n\n**Queue Implementation**\n\n");
    int ch;
    while(1)
    {
        printf("1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.display\n");
        printf("4.exit\n");
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
void enqueue()
{    
    if(rear==SIZE)
    {
        printf("\nQueue is Full\n\n");
    }
    else
    {
        
        printf("Enter the data : ");
        scanf("%d",&que[rear++]);
        printf("\n\n%d is added succesfully\n\n",que[rear-1]);

    }
}

void dequeue()
{
    if(rear==0)
    {
        printf("\n\nQueue is Empty\n\n");
    }
    else
    {
        int i;
        printf("\n\n%d is deleted\n\n",que[0]);
        for(i=0;i<rear-1;i++)
        {
            que[i]=que[i+1];
        }
        rear--;
    }

}

void display()
{
    if(rear==0)
    {
        printf("\n\nQueue is Empty\n\n");
    }
    else
    {
        int i;
        printf("\n\n");
        for(i=0;i<rear;i++)
        {
            printf("%d ",que[i]);
        }
        printf("\n\n");
    }

}