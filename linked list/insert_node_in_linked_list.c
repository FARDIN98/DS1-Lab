// insert a new node at the beginning in the linked list
// insert a new node at the end
#include<stdio.h>
#include<stdlib.h>


struct Node* createLinkedList(int arr[], int size);
void insertAtTheEnd(struct Node *head, int data);
void insertAtBeginning(struct Node *head, int data);
void printList(struct Node *head);
int searchInLinkedList(struct Node *head, int value);


struct Node{
    int data;
    struct Node *next;
};


int main(){
    int a[]= {3,4,5};
    struct Node *head = NULL;
    head = createLinkedList(a, 3);
    
    printList(head);

    // while (head != NULL)
    // {
    //     printf("%d -> ", head->data);
    //     head = head->next;
    // }
    // printf("NULL\n");
    // printf("Index: %d\n", searchInLinkedList(head, 4));


    // insert at beginning
    insertAtBeginning(head, 500);


    // insert at end
    // insertAtTheEnd(head, 222);
    return 0;
}

void insertAtTheEnd(struct Node *head, int data){
    struct Node *current = head;
    // Traverse and go to end of the list
    while (current->next != NULL)
    {
        current = current->next;
    }
    // create a new node with data
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    // Insert
    current->next = temp;
    printList(head);
}

void insertAtBeginning(struct Node *head, int data){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;

    struct Node *newHead = temp;
    struct Node *current = newHead;
    newHead = temp;
    printList(newHead);
}

void printList(struct Node *head){
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int searchInLinkedList(struct Node *head, int value){
    int index = 1;
    // head যতক্ষন NULL না হবে ততক্ষন লুপ চলতে থাকবে
    while (head != NULL)
    {
        // আমরা যে নাম্বার খুজতেছি সেটা যদি পেয়ে যাই তাহলে ইনডেক্স টা রিটার্ন করে দিবে
        if(head->data == value){
            return index;
        }
        // আর যে নাম্বার খুজতেছি সেটা যদি না পাই তাহলে ইনডেক্স এর মান ১ করে বাড়বে
        index++;
        // head যে পয়েন্টার আছে তাকে ১ ঘর সামনে নিয়ে যাবো
        head = head->next;
    }
    return -1;
}

struct Node* createLinkedList(int arr[], int size){
    struct Node *head = NULL, *temp = NULL, *current = NULL;
    int i;
    for ( i = 0; i < size; i++)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            current = temp;
        }else{
            current->next = temp;
            current = current->next;
        }
    }
    return head;   
}
