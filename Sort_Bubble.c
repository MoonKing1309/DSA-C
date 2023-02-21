#include <stdio.h>

void bubblesort(int array[],int length)
{
    int i,j,temp,swap;
    for(i=0;i<length-1;i++)
    {
        for(j=0;j<length -i-1 ;j++)
        {
            printf("i is %d and j is %d Comparing %d and %d : \n",i,j,array[j],array[j+1]);
            if(array[j]>array[j+1])
            {
                swap = array[j];
                array[j] = array[j+1];
                array[j+1] = swap;
            }
        }
    }
    printf("printing elements after sorting : \n");
    for (i=0;i<length;i++)
    {
        printf("%d\t",array[i]);
    }
}
int main()
{
    int length;
    printf("enter length : ");
    scanf("%d",&length);
    int array[length];
    for (int i =0;i<length;i++)
    {
        printf("enter element %d\n" , (i+1));
        scanf("%d",&array[i]);
    }
    bubblesort(array,length);
}