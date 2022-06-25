#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selectionSort(int data[], int n);

int main(){
    // int array[100], size, c, location = 0;

    // printf("Enter number of elements in array\n");
    // scanf("%d", &size);

    // printf("Enter %d integers\n", size);

    // for (c = 0; c < size; c++)
    // scanf("%d", &array[c]);

    // for (c = 1; c < size; c++)
    //     if (array[c] < array[location])
    //         location = c;

    // printf("Minimum element is present at location %d and its value is %d.\n", location+1, array[location]);
    // return 0;

    int data[100], n, i;
    printf("Enter array size: ");
    scanf("%d", &n);
    // for determining current time we use null
    srand(time(NULL));
    
    for ( i = 0; i < n; i++)
    {
        data[i] = rand()%100+1;
    }
    printf("before sorting: ");
    for ( i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }

    selectionSort(data, n);
    printf("\n\nAfter sorting: ");
    // for ( i = 0; i < n; i++)
    // {
    //     data[i] = rand()%100+1;
    // }
    for ( i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }
}

void selectionSort(int data[], int n){
    int i,j, minIndex, temp;
    for(i = 0; i < n-1; i++){
        minIndex = i;
        for(j = i + 1; j < n; j++){
            if(data[j] < data[minIndex]){
                minIndex = j;
            }
        }
        temp = data[i];
        data[i] = data[minIndex];
        data[minIndex] = temp;

    }

}