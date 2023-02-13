//Stack using array
#include <stdio.h>
#include <malloc.h>
struct stack
{
    int size;
    int*array;
    int top;
};
void push(struct stack* ptr)
{
    int item;
    printf("Enter item to input :\t");
    scanf("%d",&item);
    if(ptr->top==ptr->size-1){
        printf("Stack Overflow");
    }
    else{
        ptr->top++;
        ptr->array[ptr->top] = item;
    }
}

int pop(struct stack *s1)
{
    if(s1->top==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        int p = s1->array[s1->top];
        s1->top--;
        return p;
    }
}
void display(struct stack *s1)
{
    int i =0;
    if(s1->top>=0)
    {
        while(i<=s1->top)
        {
            printf("%d", s1->array[i]);
            i++;
        }
    }
    else
    {
        printf("Underflow\n");
    }
}

void main()
{
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->array = (int *)malloc(s->size * sizeof(int));
    int choice=5;
    while(choice!=0)
    {
        printf("\n\n0.Exit\n1.Push\n2.Pop\n3.Display:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            { 
                push(s);
                break;
            }
            case 2:
            {
                printf("%d",pop(s));
                break;
            }
            case 3:
            {
                display(s);
                break;
            }
        }       
    }
}

