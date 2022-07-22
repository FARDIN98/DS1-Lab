#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next=nullptr;
    Node(int x){
        data=x;
    }
};
void printLinkedList(Node* head){
    while(head!=nullptr){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"nullptr"<<endl;
}
void insertNode(Node*& head, int data){
    if(head==nullptr){
        head=new Node(data);
        return;
    }
    Node* n= head;
    while(n->next!=nullptr){
        n= n->next;
    }
    n->next= new Node(data);
    return;
}
void addToHead(Node*& head, int data){
    Node* newNode= new Node(data);
    newNode->next=head;
    head=newNode;
}
void addAfter(Node*& head, int data, int key){
    Node* newNode=new Node(data);
    Node* n= head;
    while(n->data!=key){
        n=n->next;
    }
    newNode->next= n->next;
    n->next=newNode;
}
void addBefore(Node*& head, int data, int key){
    Node* newNode = new Node(data);
    Node* n = head;
    Node* prev=nullptr;
    while(n->data!=key){
        prev=n;
        n=n->next;
    }
    if(prev==nullptr){
        addToHead(head, data);
        return;
    }
    prev->next=newNode;
    newNode->next=n;
}
int main(){
    Node* head=nullptr;
    insertNode(head, 5);
    insertNode(head, 10);
    insertNode(head, 15);
    addToHead(head, 1);
    addAfter(head, 7, 5);
    addBefore(head, 0, 1);
    printLinkedList(head);
}