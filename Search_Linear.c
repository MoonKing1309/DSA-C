#include <stdio.h>

int main()
{
    int length,i;
    printf("Enter length:\t");
    scanf("%d",&length);
    int a[length],present;
    for(i=0;i<length;i++)
    {
        printf("Enter a[%d]:\t",i);
        scanf("%d",&a[i]);
        printf("");
    }
    int sn;
    printf("Enter element to search for :\t");
    scanf("%d",&sn);
    int choice;
    printf("Is array sorted? 1 for yes and 0 for no:\t");
    scanf("%d",&choice);
    if(choice ==1)
    {
        if(sn>=a[0] && sn<=a[length-1])
        {
            for(i=0;i<length;i++)
            {
                if(a[i]==sn)
                {
                    printf("Element present at %d.",i);
                    break;
                }
                else
                {
                    int present = -1;
                }
            }   
        }
        else
        {
            printf("Element not present in array.");
        }
    }
    else if(choice == 0)
    {
        for(i=0;i<length;i++)
            {
                if(a[i]==sn)
                {
                    printf("Element present at %d.",i);
                    break;
                }
                else
                {
                    int present = -1;
                }
            }   
    }

    if(present ==-1)
    {
        printf("Element not present");
    }
}