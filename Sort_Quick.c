#include <stdio.h>

int split(int a[] , int l , int u)
{

   int pivot = a[l], left = l+1,right = u;
   int temp;
   {
    while(a[left] <=pivot)
    {
        left++;
    }
    while (a[right]>pivot)
    {
        right--;
    }
    if(left<right)
    {
        temp = a[left];
        a[left] = a[right];
        a[right] = temp;
    }
   }
   while(left<right);

    temp = a[l];
    a[l] = a[right];
    a[right] = temp;
    return right;
}



void  quicksort(int a[],int l , int u)
{
   int i;
   if(l<u)
   {
    i = split(a,l,u);
    quicksort(a,l,i-1);
    quicksort(a,i+1,u);                                            
   }
   
   
}


int main()
{
  int length,i;
    printf("Enter length:\t");
    scanf("%d",&length);
    int a[length];
   for(i=0;i<length;i++)
    {
        printf("Enter a[%d]:\t",i);
        scanf("%d",&a[i]);
        printf("");
    }
    quicksort(a,0,length-1);
    printf("After sorting : \t");
    for(i=0;i<length;i++)
    {
        printf("%d\t",a[i]);
    }
}