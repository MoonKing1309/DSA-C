#include <stdio.h>
int binarySearch(int arr[], int x, int low, int high){
    if(low > high)
        return -1;
    else
        {int mid = (low + high) / 2 ;
        if( x == arr[mid])
            {return mid;}
        else if( x > arr[mid] )
            {return binarySearch(arr, x, mid + 1, high);}
        else                               
           { return binarySearch(arr, x, low, mid - 1);}
        }
}
void main()
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
    int result = binarySearch(a, sn, 0, length - 1);
    if (result == -1)
    printf("Not found");
    else
    printf("Element is found at %d", result);
}