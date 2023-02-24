#include <stdio.h>
void IS(int a[] , int length)
{
    int i,j,element;
    for(i=1;i<length;i++)
    {
        element = a[i];
        j = i-1;
        while(j>=0 && a[j]>element)
        {
            a[j+1] = a[j];
            j--;     
        }
        a[j+1] = element;
    }
    printf("Sorted array is:\t");
    for(i=0;i<length;i++)
    {
        printf("%d\t",a[i]);
    }

}
int main()
{
    int length;
    printf("Enter the length of array:\t");
    scanf("%d",&length);
    int a[length];
    int i;
    for(i=0;i<length;i++)
    {
        printf("Enter a[%d]:\t",i+1);
        scanf("%d",&a[i]);
    }
    IS(a,length);
    return 0;
}
