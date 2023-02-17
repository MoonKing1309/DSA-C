//Circular SinglyLinked List

#include <stdio.h>
#include <malloc.h>
int n;
struct node
{
    int data;
    struct node * next;
};struct node * temp,*head,*tail,*nw;

void create()
{
    int i =0;
    int item;
    printf("Enter length of LL : ");
    scanf("%d",&n);
    while(i< n)
    {
        printf("Enter Element : ");
        scanf("%d",&item);
        if (nw->data==-12345)
        {
            nw->data = item;
        }
        else
        {
            nw = (struct node*)malloc (sizeof(struct node));
            tail->next =nw;
            nw->data = item;
            nw->next = head;
            tail = nw;
        }
        i++;
    }
}

void Display()
{
    temp = head;

do{
    printf("%d\t",temp->data);
        temp=temp->next;
}
    while(temp!=head);
    printf("\n");
}
void Reverse(int count)
{
    int i=0;
    temp = head;
    if(count==1)
    {
        printf("%d",head->data);
    }
    else
    {
        while(i<count-1)
        {
            temp = temp->next;
            i++;
        }
        printf("%d\t" , temp->data);
        Reverse(count -1);
        
    }
    printf("\n");
}
void Insert()
{
    int i=0;
    int item;
    printf("Enter Element to be inserted: ");
    scanf("%d",&item);
    int pos;
    printf("Enter Position : ");
    scanf("%d",&pos);
    if(pos == 0)
    {
        nw = (struct node *)malloc(sizeof(struct node));
        nw->next = head;
        nw->data = item;
        head = nw;
        tail->next = head;
    }
    else if (pos ==n)
    {
        nw =(struct node *)malloc(sizeof(struct node));
        nw->next = head;
        tail->next = nw;
        nw->data = item;
        tail =nw;
    }
    else 
    {
        int i=0;
        nw = (struct node *)malloc(sizeof(struct node));
        temp=head;
        while(i < pos-1)
        {
            temp= temp->next;
            i++;
        }
        nw->next = temp->next;
        temp->next = nw;
        nw->data = item;
    }
    n++;
}

void Delete()
{
    int i =0;
    int pos;
    printf("Enter Position : ");
    scanf("%d",&pos);
    if(pos==0)
    {
        head=head->next;
    }
    else if (pos == n-1)
    {
        i=0;
        temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        temp->next = head;
    }
    else
    {
        i=0;
        temp=head;
        while(i < pos -1)
        {
            temp=temp->next;
            i++;
        }
        temp->next = temp->next->next;
    }
    n--;
}


int main()
{
    nw = (struct node *)malloc(sizeof(struct node));
    nw->data = -12345;
    head = nw;
    tail = nw; 
    nw->next = NULL;
    int c = 1000;
    while(c!=0)
    {
        printf("Length of LL is %d \nEnter \n0.Quit\n1.Create\n2.Display\n3.Insert\n4.Delete:",n);
        scanf("%d",&c);
        switch (c)
        {
            case 1:
            {
                nw = (struct node *)malloc(sizeof(struct node));
                nw->data = -12345;
                head = nw;
                tail = nw; 
                nw->next = NULL;
                create();
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