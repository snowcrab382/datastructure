#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

int list[10];
int n;

int partition(int list[], int left, int right)
{
    int pivot, tmp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left];
    do {
        do 
            low++;
            while (list[low] < pivot);
        do 
            high--;
            while (list[high] > pivot);
        if (low < high)
            SWAP(list[low], list[high], tmp);
    } while (low < high);

    SWAP(list[left], list[high], tmp);
    return high;
}

void quick_sort(int list[], int left, int right)
{
    if (left < right)
    {
        int q = partition(list, left, right);
        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1, right);
    }
}


void print_array(int list[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main(void)
{
    int a[10] = {6, 2, 1, 5, 2, 7, 3, 9, 10, 4};

    quick_sort(a, 0, 10);
    print_array(a, 10);

    return 0;
}