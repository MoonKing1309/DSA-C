#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};struct node *parent, *temp,*nw;

struct node *newNode(int data)
{
    nw = (struct node *)malloc (sizeof(struct node));
    nw->data = data;
    nw->left = NULL;
    nw->right = NULL;
    return nw;
}

struct node* insert(struct node * root , int data)
{  
    if(root == NULL)
    {
        return newNode(data);
    }
    if(data < root->data)
    {
        root->left = insert(root->left , data);
    }
    else if(data > root->data)
    {
        root->right = insert(root->right , data);
    }
    return root;
}

void create ( struct node * root)
{
    int length;
    printf("Enter length : ");
    scanf("%d", &length);
    int i =0,item;
    for(i=0;i<length;i++)
    {
        printf("Enter item : ");
        scanf("%d", &item);
        if(root==NULL)
        {
            parent = newNode(item);
            root= parent;
        }
        else
        {
            insert(root,item);
        }
    }
}
void inorder(struct node * root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}

void preorder(struct node * root)
{
    if(root != NULL)
    {
        printf("%d", root->data);
        inorder(root->left);
        inorder(root->right);
    }
}

void postorder(struct node * root)
{
    if(root != NULL)
    {
   
        inorder(root->left);
        inorder(root->right);
        printf("%d", root->data);
    }
}

void findmin(struct node * root)
{
    if(root->left!=NULL)
    { 
       findmin(root->left);
    }
    else
    {
        printf("%d",root->data);
    }
}

void findmax(struct node * root)
{
    if(root->right!=NULL)
    {
       findmax(root->right);
    }
    else
    {
        printf("%d",root->data);
    }
}

void sort(struct node * root)
{
    inorder(root);
}

struct node * copy(struct node * root)
{
    if(root == NULL)
    {
        return NULL;
    }
    struct node * newTree = newNode(root->data);
    newTree->left = copy(root->left);
    newTree->right = copy(root->right);
    return newTree;
}

struct node *inorderPre(struct node * root)
{
    while(root->left!=NULL)
    {
        root = root->left;
    }
    return root;
}
struct node* delete(struct node *root , int item)
{
    struct node * iordPre;
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if(item<root->data)
    {
        root->left = delete(root->left,item);
    }
    else if (item >root->data)
    {
        root->right =delete(root->right , item);
    }
    else
    {
        iordPre = inorderPre(root->right);
        root->data `= iordPre->data;
        root->left = delete(root->left,iordPre->data);
    }
    return root;
}


int search(struct node *root,int item)
{
    if(root==NULL)
    {
        printf("Item not in tree...");
        return 0;
    }
    else if(root->data == item)
    {
       printf("Found item in tree!!");
       return 1;
    }
    else if (root->data > item)
    {
        search(root->left,item);
    }
    else if(root->data < item)
    {
        search(root->right,item);
    }

}

int main()
{
    int item,present;
    parent = NULL;
    create(parent);
    printf("Minimum is : ");
    findmin(parent);printf("\n");
    printf("Maximum is : ");
    findmax(parent);printf("\n");
    printf("Sorted is : ");
    sort(parent);printf("\n");
    struct node*parent2 = copy(parent);
    printf("The copied BST is : ");
    inorder(parent2);printf("\n");
    printf("Enter element to search for : ");
    scanf("%d",&item);
    search(parent,item);printf("\n");
    printf("Enter element to delete : ");
    scanf("%d",&item);printf("\n");
    present = search(parent,item);
    if(present ==0)
    {
        printf("Element not in tree...");
    }
    else if (present ==1)
    {
        delete(parent,item);
       
    }
     printf("\nTree(inorder) : ");
    inorder(parent);

}