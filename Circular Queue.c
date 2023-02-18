// Circular Queue 

#include <stdio.h>

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

void enQueue(int element) {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf("\n Inserted -> %d", element);
  }
}


int deQueue() {
  int element;
  if (front == -1) {
    printf("\n Queue is empty !! \n");
    return (-1);
  } else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    else {
      front = (front + 1) % SIZE;
    }
    printf("\n Deleted element -> %d \n", element);
    return (element);
  }
}

void display() {
  int i;
  if (front == -1)
    printf(" \n Empty Queue\n");
  else {
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
  }
}

int main() {
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
                enQueue(item);
                break;
            }
            case 2:
            {
                deQueue();
                break;
            }
            case 3:
            {
                display();
                break;
            }
        }
    }
  return 0;
}