#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int pos;

int searching(int arr[], int len, int s){
    int i;
    for(i = 0; i<=len; i++){
        if(arr[i]==s){
            pos = i;
            return 1;
        }
    }
    return -1;
}




int main(){
    int data[100], n, i, s;

    printf("enter array size: ");
    scanf("%d",&n);
    srand(time(NULL));
    for ( i = 0; i < n; i++)
    {   
        data[i] = rand()%100+1;
    }

    for ( i = 0; i < n; i++)
    {
        printf("%d  ", data[i]);
    }
    printf("Search?\n");
    scanf("%d", &s);

    int res =  searching(data, n ,s);
    if(res == 1){
        printf("Found @ position: %d", pos);
    }  
    else{
        printf("Not found");
    }
}
