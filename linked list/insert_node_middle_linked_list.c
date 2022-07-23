// Insert a node in a linked list(middle)

#include<stdio.h>
#include<stdlib.h>

struct Node* createLinkedList(int arr[], int size);
void Print(struct Node *head);
// আমরা হেড নাম এ একটা পয়েন্টার বানাই, কত তম পজিশনে নতুন নোড ইন্সার্ট করতে চাই আর সেই নোড এর মান কত সেটা বলে দিতে হবে
void insert(struct Node *head, int position, int value);

struct Node{
    int data;
    struct Node *next;
};

int main(){
    int a[] = {15,20,25};
    struct Node *head  = NULL;
    head  = createLinkedList(a, 3);
    Print(head);
    insert(head, 1, 155);
    return 0;
}

// Output:
// 15 -> 20 -> 25 -> NULL
// 15 -> 155 -> 20 -> 25 -> NULL

// insert node at nth position
void insert(struct Node *head, int position, int value){
    // আমরা টেম্প নাম এ একটা পয়েন্টার বানাই আর তার মধ্যে হেড কে রাখি যেনো হেড এর মান যখন প্যারামিটার হিসেবে নিবো তার মান যেনো চেঞ্জ না হয়
    struct Node *temp = head;
    // কত তম পজিশন এ ইন্সার্ট করবো তা বুঝার জন্য কাউন্টার ব্যবহার করব
    int counter = 0;
    // এখন যেহেতু টেম্প এর ভেতর হেড এর মান আছে আর টেম্প এর প্রত্যেকটি ইটারেশনে যতক্ষন না পর্যন্ত ভ্যালু নাল হবে ততক্ষন লুপ চলতে থাকবে
    while (temp != NULL)
    {
        // প্রত্যেকবার কাউন্টার এর মান ১ করে বাড়াবে পজিশন চেক করার জন্য
        counter++;
        // আমরা যে পজিশনে ভ্যালু ইন্সার্ট করতে চাচ্ছি কাউন্টার এর মাধ্যমে যদি সেই পজিশন পেয়ে যাই তাহলে কন্ডিশনে ঢুকবে
        if (counter == position)
        {
            // insert your node here
            struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
            // newNode যেটা বানিয়েছি সেটার মধ্যে আমরা ফাংশনের প্যরামিটারের মধ্যে যে ভ্যালু দিয়েছি সেটা জমা রাখবো
            newNode->data = value;
            // newNode নেক্সট পয়েন্টার কে পয়েন্ট করবে টেম্প এর যে নেক্সট পয়েন্টার আছে সেটা
            // 155 -> 20
            newNode->next = temp->next;
            // 15 -> 155
            temp->next = newNode;
        }
        temp = temp->next;
    }
    Print(head);
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

void Print(struct Node *head){
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}