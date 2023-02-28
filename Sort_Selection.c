#include <stdio.h>
void SS(int a[],int length)
{
    int i,j,swap;
    for(i=0;i<length-1;i++)
    {
        for(j=i+1;j<length;j++)
        {
            if(a[i]>a[j])
            {
                swap =a[i];
                a[i]=a[j];
                a[j]=swap;
            }

        }
    }
    for(i=0;i<length;i++)
    {
        printf("%d",a[i]);
    }
}

void main()
{
    int length,i;
    printf("Enter the length :\t");
    scanf("%d",&length);
    int array[length];
    for(i=0;i<length;i++)
    {
        printf("Enter element %d :\t",i+1);
        scanf("%d",&array[i]);
    }
    SS(array,length);
}