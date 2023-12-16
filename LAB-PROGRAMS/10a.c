//Quick Sort Implementation

#include<stdio.h>
void quicksort();
int main()
{
    int n,i;
    printf("Enter the array size : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the numbers \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    printf("Sorted array \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    

}
void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int i=low,temp;
        int j=high;
        int pivot=low;
        while(i<j)
        {
            while(a[i]<=a[pivot])
            {
                i++;
            }
            while(a[j]>a[pivot])
            {
                j--;
            }
            if(i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
            temp=a[j];
            a[j]=a[pivot];
            a[pivot]=temp;

            quicksort(a,low,j-1);
            quicksort(a,j+1,high);
        }
    }
}