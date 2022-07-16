#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selectionSort(int data[], int n);
void bubbleSort(int data[], int n);
void insertionSort(int data[], int n);


int i;
int main()
{
    //printf("hello");

    int data[100], n, i;



    printf("enter array size: ");
    scanf("%d",&n);
    srand(time(NULL));
    for(i = 0; i < n; i++)
    {
        //scanf("%d",&data[i]);
        data[i] = rand()%100+1;
    }
    printf("before sorting: ");
    for(i = 0; i < n; i++)
    {
        //scanf("%d",&data[i]);
        printf("%d ", data[i]);
    }

    //selectionSort(data, n);
    //bubbleSort(data, n);
    insertionSort(data, n);
    printf("\n\nafter sorting: ");
    for(i = 0; i < n; i++)
    {
        //scanf("%d",&data[i]);
        printf("%d ", data[i]);
    }
}


void selectionSort(int data[], int n)
{
    int i, j, minIndex, temp;
    for(i = 0; i < n-1 ; i++)
    {
        minIndex = i;
        for(j = i+1; j < n; j++)
        {
            if(data[j] < data[minIndex])
            {
                minIndex = j;
            }

        }
        temp = data[i];
        data[i] = data[minIndex];
        data[minIndex] = temp;
    }

}


void bubbleSort(int data[], int n)
{
    int i, j, temp;

    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-1-i; j++)
        {
            if(data[j] > data[j+1])
            {
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }

}

void insertionSort(int data[], int n)
{
    int i, j, key;

    for(i = 1; i < n; i++)
    {
        key = data[i];
        j = i-1;

        while(j >= 0 && data[j] > key)
        {
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = key;
    }
}

int binarySearch(int data[], int n, int s){
    bubbleSort(data, n);
    int lo=0, hi = n -1, mid;

    while (lo <= hi){
        mid = (lo + hi)/2;
        if (s==data[mid])
        {
            return 1;
        }
        else if (data [mid] < s)
        {
            lo = mid + 1;
        }
        else{
            hi = mid -1 ;
        }
    }
    return 0;
}

float sq_root (int data[], int n, int sq){
    int high = sq, low = 0, mid = 0;

    while (low <= high)
    {

        mid = (low + high) / 2;
        if(data[mid]*2==sq){
            return data[mid];
        }
        else if(data[mid] *2 < sq){
            high = mid;
        }
        else{
            low  = mid;
        }

        // mid  = (low + high) /2;

        // int test = data[mid] * 2;
        // if(test < (sq + 0.005) || test > (sq - 0.005)){
        //     return data[mid];
        // }
        // else if (test < ){}
    }
    

}

