//4.write a program to implement the stack using array

#include<stdio.h>
#include<stdlib.h>
//Function Decleration
void push();
void pop();
int length();
void display();

int top=-1;
int size;
int stack[100];

int main()
{
     printf("\n\nStack Implementation\n\n");
    printf("Enter the size of Stack : ");
    scanf("%d",&size);
   
    int ch,l;
	while(1)
	{
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.length\n");
		printf("4.dispaly\n");
		printf("5.exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);

		switch (ch)
		{
		case 1:push();
			break;
		case 2:pop();
			break;
		case 3:l=length();
        if(l==0)
        {
            printf("\n\nStack is Empty\n\n");
        }
        else
        {
            printf("\n\nSize=%d\n\n",l);
        }
			break;
		case 4:display();
			break;
		case 5:exit(0);	
		default:
			printf("Invalid entry\n");
		}
		printf("\n\n");
		
	}

    return 0;
}
void push()
{
    int ele;
    if(top==size-1)
    {
        printf("\n\nStack is overflow\n\n");
    }
    else
    {
        printf("\nEnter the data :");
        scanf("%d",&ele);
        printf("\n\n%d is pushed into the stack\n\n",stack[++top]=ele);
    }

}
void pop()
{
    if(top==-1)
    {
        printf("\n\nStack is under flow\n\n");
    }
    else
    {
        printf("\n\n %d is poped from stack",stack[top--]);
    }

}
int length()
{
    int count=0;
    if(top==-1)
    {
        return count;
    }
    else
    {
        int i;
        for(i=0;i<=top;i++)
        {
            count++;
        }        
    }
    return count;

}
void display()
{
    if(top==-1)
    {
        printf("\n\nStack is Empty\n\n");
    }
    else
    {
        int i;
        for(i=0;i<=top;i++)
        {
            printf("%d ",stack[i]);
        }  
        printf("\n\n");      
    }

}