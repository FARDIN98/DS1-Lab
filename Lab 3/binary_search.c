#include <stdio.h>
int main()
{
    int a[] = {5, 10, 15, 20, 25, 30};
    int item = 30;

    int high, low, middle;

    low = 0;
    high = 5;

    while (low <= high)
    {
        middle = (low + high) / 2;

        if (a[middle] == item)
        {
            printf("Item found at %d position", middle);
            return 0;
        }
        else if (a[middle] < item)
        {
            low = middle + 1;
        }
        else
        {
            high = middle - 1;
        }
    }
    printf("Not Found");
    return 0;
}