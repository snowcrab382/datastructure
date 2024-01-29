#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int list[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = list[i];
        for (j = i - 1; j >= 0 && list[j] > key; j--)
        {
            list[j + 1] = list[j];
        }
        list[j + 1] = key;
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

    insertion_sort(a, 10);
    print_array(a, 10);

    return 0;
}