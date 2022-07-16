#include<stdio.h>

struct student{
    int age;
}s1;

int main(){
    printf("Enter age:");
    scanf("%d", &s1.age);
    printf("Age is: %d", s1.age);
    return 0;
}