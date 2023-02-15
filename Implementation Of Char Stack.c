#include <stdio.h>

int display(char * array)
{
    while(*array != '\0')
    {
        printf("%c",*array);
        *array++;
    }
    printf("\n");
}
void push(char *array, char  * element)
{
   while(*array != '\0')
   {
        *array++;
   }
 
    while(*element != '\0')
    {
        *array = *element;
        *array++;
        *element++;
    }
}

char pop(char * array)
{
    while(*array !='\0')
    {
        *array++;
    }
    *array--;
    char temp = *array;
    *array = '\0';
    return temp;
}
int main()
{
    char array[32] ;
    printf("Please enter the input expression");
    getch(&array);
    char *stack = array;

}

