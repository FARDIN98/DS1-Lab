// search an element/item in a linked list

#include<stdio.h>
#include<stdlib.h>


struct Node* createLinkedList(int arr[], int size);
int searchInLinkedList(struct Node *head, int value);

struct Node{
    int data;
    struct Node *next;
};


int main(){
    int a[]= {3,4,5};
    struct Node *head = NULL;
    head = createLinkedList(a, 3);
    // Now We dont print the linked list that commenting out line Number 19-24
    // while (head != NULL)
    // {
    //     printf("%d -> ", head->data);
    //     head = head->next;
    // }
    // printf("NULL\n");
    printf("Index: %d\n", searchInLinkedList(head, 4));
    return 0;
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

