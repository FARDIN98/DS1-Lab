#include<stdio.h>
int main(){
    int data[10];
    int *p;
    p = data;

    printf("p: %d\n", p);
    printf("data: %d\n", data);
    printf("data[0]: %d\n", &data[0]);
    printf("data[1]: %d\n", &data[1]);
    p+=3;
    printf("p(after increment): %d\n", p);
    return 0;
}