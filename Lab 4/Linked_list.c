#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

// Node *create_node(int item, Node *next){
//     Node *new_node = (Node *)malloc(sizeof(Node));
// };

int main(){
    struct Node *a = NULL;
    struct Node *b = NULL;
    struct Node *c = NULL;

    // malloc() default returns void. so we converted into struct Node that return type would be (struct Node)
    a = (struct Node*)malloc(sizeof(struct Node));
    b = (struct Node*)malloc(sizeof(struct Node));
    c = (struct Node*)malloc(sizeof(struct Node));


    a->data = 10;
    b->data = 20;
    c->data = 30;
    a->next = b;
    b->next = c;
    c->next = NULL; 

    while (a != NULL)
    {
        printf("%d ->", a->data);
        a = a->next;
    }
    

    return 0;
}