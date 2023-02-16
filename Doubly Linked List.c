//Doubly Linked List

#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    struct node *prev;  
    struct node *next;  
    int data;  
};struct node *head,*tail,*nw,*temp;

void Create()
{
    int length;
    printf("Enter length : ");
    scanf("%d",&length);
    for(int i =0;i<length;i++)
    {
        int item;
        printf("Enter item : ");
        scanf("%d",&item);
        if(head->data ==12345)
        {
            head ->data = item;
       }
        else
        {
            nw=(struct node*)malloc(sizeof(struct node));
            nw->data = item;
            tail->next = nw;
            nw->prev = tail;
            nw->next=NULL;
            tail = nw;  
        }
    }
}
void Display()
{
    temp=head;
    while(temp!= NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void Delete()
{
    temp=head;
    int pos,i=0;
    while(temp!= NULL)
    {
        temp=temp->next;
        i++;
    }
    temp=head;
    printf("Enter the pos to delete at : ");
    scanf("%d",&pos);
    if(pos==0)
    {
        head->next->prev = NULL;
        head = head->next;
    }
    else if (pos == i-1)
    {
        tail=tail->prev;
        tail->next = NULL;
    }
   
    else
    {
        temp=head;
        for(i=0;i<pos-1;i++)
        {
            temp = temp->next;
        }
        temp->next->next->prev = temp;
        temp->next = temp->next->next;
    }

}

void Insert()
{
    temp=head;
    int pos,i=0;
    while(temp!= NULL)
    {
        temp=temp->next;
        i++;
    }
    printf("\nLength of ll is %d\n",i);
    printf("Enter the pos to insert at : ");
    scanf("%d",&pos);
    
    temp=head;
    int item;
    printf("Enter item : ");
    scanf("%d",&item);
    nw = (struct node*)malloc(sizeof(struct node));
    if(pos==0)
    {
        nw->data = item;
        nw->prev = NULL;
        nw->next = head;
        head->prev = nw;
        head =nw;
    }
    else if (pos == i)
    {
        nw->data =item;
        nw->next =NULL;
        tail->next =nw;
        nw->prev=tail;
        tail=nw;

    }
   
    else
    {
        temp=head;
        for(i=0;i<pos-1;i++)
        {
            temp = temp->next;
        }
       temp->next->prev = nw;
       nw->next = temp->next;
       temp->next = nw;
       nw->prev = temp;
       nw->data = item;

    }
}

void main()
{
    int c = 1000;
    while(c!=0)
    {
        printf("Enter \n0.Quit\n1.Create\n2.Display\n3.Insert\n4.Delete\t:");
        scanf("%d",&c);
        switch (c)
        {
            case 1:
            {
                nw = (struct node*)malloc(sizeof(struct node));
                nw->data = 12345;
                head = nw;
                tail = nw; 
                nw->next = NULL;
                nw->prev = NULL;
                Create();
                break;
            }
            case 2:
            {
                Display();
                break;
            }
            case 3:
            {
                Insert();
                break;
            }
            case 4:
            {
                Delete();
                break;
            }
        }
    }
}