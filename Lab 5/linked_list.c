// #include<stdio.h>
// int main(){
//     int data[10];
//     int *p;
//     p = data;

//     printf("p: %d\n", p);
//     printf("data: %d\n", data);
//     printf("data[0]: %d\n", &data[0]);
//     printf("data[1]: %d\n", &data[1]);
//     p+=3;
//     printf("p(after increment): %d\n", p);
//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>




struct Node{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    
}


int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;

    // Allocate memory for nodes in the linked list in heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // link first and second nodes
    head->data = 7;
    head->next = second;


    // link second and third nodes
    second->data =  11;
    second->next = third;


    // Terminate the list at the third node
    third->data = 55;
    third->next = NULL;


    linkedListTraversal(head);

    return 0;
}