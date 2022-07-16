#include<stdio.h>

struct Node{
    int data;

    struct Node *next;
};
typedef struct Node node;

void menu();
node* createNode();
void listPrint(node *head);



int main(){
    node *head = NULL:
    int ch;

    menu();
    printf("Enter choice: ");
    scanf("%d", &ch);

    while (ch != 0)
    {
        if (ch == 1)
        {
            nn = create_node();
            insert_head(head, nn);
        }
        else if (ch == 2)
        {
            
        }
        else if (ch == 3)
        {
            nn = create_node();

        }
        else if (ch == 8)
        {
            
        }
        else if (ch == 9)
        {
            
        }
        else{
            printf("Invalid Input\n");
        }
        menu();
        printf("Enter choice: ");
        scanf("%d", &ch);
    }
    
}

menu(){
    printf("1.Insert (head)\n");
    printf("2.Insert (nth)\n");
    printf("3.Insert (tail)\n");
    printf("8.Print list\n");
    printf("9.List Size\n");
    printf("6.Exit\n");
}

node* create_node(){
    node *nn = new node();
    printf("Enter value: ");
    scanf("%d", &nn->data);
    nn->next = NULL;
    return nn;
}

node* insert_head(node *head, node *nn){
    if(head != NULL){
        nn->next = head;
    }
    head = nn;
    return head;
    
}

void listPrint(node *head){
    node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp  = temp->next;
    }
    printf("\n\n");
    
}



node* insert_tail(node *head, node *nn){
    if(head == NULL){
        head = insert_head(head, nn);
    }
    else{
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
    return head;
}
