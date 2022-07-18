#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;


void menu();
node* createNode();
void listPrint(node *head);
node* insert_head(node *head, node *nn);
node* insert_tail(node *head, node *nn);

int main()
{
    node *head = NULL, *nn, *temp;
    int ch;

    menu();
    printf("enter choice: ");
    scanf("%d",&ch);

    while(ch != 0)
    {
        if(ch == 1)
        {
            nn = createNode();
            head = insert_head(head, nn);
        }
        else if(ch == 2)
        {

        }
        else if(ch == 3)
        {
            nn = createNode();
            head = insert_tail(head, nn);
        }
        else if(ch == 8)
        {
            listPrint(head);
        }
        else if(ch == 9)
        {

        }
        else
        {
            printf("wrong input.\n\n");
        }
        menu();
        printf("enter choice: ");
        scanf("%d",&ch);
    }

}

void menu()
{
    printf("1. insert(head)\n");
    printf("2. insert(nth)\n");
    printf("3. insert(tail)\n");
    printf("8. print list\n");
    printf("9. list size\n");
    printf("0. exit\n");
}

node* createNode()
{
    node *nn = new node();
    printf("enter value: ");
    scanf("%d",&nn->data);
    nn->next = NULL;
    return nn;
}

node* insert_head(node *head, node *nn)
{
    if(head != NULL)
    {
        nn->next = head;
    }
    head = nn;
    return head;
}

void listPrint(node *head)
{
    node *temp;
    temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

node* insert_tail(node *head, node *nn)
{
    if(head == NULL)
    {
        head = insert_head(head, nn);
    }
    else
    {
        node *temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }

    return head;
}