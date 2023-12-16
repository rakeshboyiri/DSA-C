//Merge Sort Implementation

#include<stdio.h>
void mergesort();
void merge();

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
    mergesort(a,0,n-1);
    printf("Sorted array \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    

}
void mergesort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void merge(int a[],int low,int mid,int high)
{
    int i=low;
    int k=low;
    int j=mid+1;
    int b[high-low+1];
    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
        {
            b[k++]=a[i++];
        }
        else
        {
            b[k++]=a[j++];
        }
    }
    while(i<=mid)
    {
        b[k++]=a[i++];
    }
    while(j<=high)
    {
        b[k++]=a[j++];
    }
    for(i=low;i<=high;i++)
    {
        a[i]=b[i];
    }
    
}
         