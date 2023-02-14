//QUEUE USING ARRAY
#include <malloc.h>
#include <stdio.h>
struct queue
{
    int front,rear,size;
    int *array;
};

void enqueue(struct queue *q,int item)
{
    if(q->rear ==(q->size-1))
    {
        printf("Queue is full\n");
    }
    else
    {
        if(q->front==-1)
        {
            q->front++;
            q->rear++;
            q->array[q->rear]=item;
        }
        else
        {
            q->rear++;
            q->array[q->rear] = item;
        }
    }
}
void dequeue(struct queue *q)
{
    if(q->front ==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        q->front++;
    }
}
void display(struct queue *q)
{
    if(q->front ==-1 && q->rear ==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i =q->front;
        while(i<=q->rear)
        {
            printf("%d",q->array[i]);
            i++;
        }
    }
}

int main()
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->size = 10;
    q->front=-1;
    q->rear=-1;
    q->array = (int *)malloc(q->size * sizeof(int));

    int choice =100;
    while(choice!=0)
    {
        printf("\n\n0.Exit\n1.Enqueue\n2.Dequeue\n3.Display:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                int item;
                printf("Enter item : \t");
                scanf("%d",&item);
                enqueue(q,item);
                break;
            }
            case 2:
            {
                dequeue(q);
                break;
            }
            case 3:
            {
                display(q);
                break;
            }
        }
    }
}