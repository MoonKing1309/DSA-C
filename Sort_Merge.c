#include <stdio.h>
void merge(int a[],int start ,int mid, int end)
{
    int i,j,k;
    int n1 = mid-start+1;
    int n2= end- mid;
    int l[n1] , r[n2];
    for(i=0;i<n1;i++)
    {
        l[i] = a[start+i];
    }
    for(j=0;j<n2;j++)
    {
        r[j] = a[mid+1+j];
    }

    i=0;j=0;k=start;
    while(i<n1 && j<n2)
    {
        if(l[i]<=r[j]){
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = r[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k] = l[i];
        i++;k++;
    }
    while(j<n2)
    {
        a[k] = r[j];
        j++;
        k++;
    }

}

void split(int a[] , int start , int end)
{
    if(start<end)
    {
        int mid = (start +end)/2;
        split(a,start,mid);
        split(a,mid+1,end);
        merge(a,start,mid,end);
    }
}


int main()
{
    int i, length;
    printf("Enter length :\t");
    scanf("%d",&length);
    int a[length];
    for(i=0;i<length;i++)
    {
        printf("\na[%d]:",i+1);
        scanf("%d",&a[i]);
    }
    split(a,0,length);
     printf("After sorting : \t");
    for(i=0;i<length;i++)
    {
        printf("%d\t",a[i]);
    }
}