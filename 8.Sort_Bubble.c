#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int list[], int n)
{
    int i, j;
    int tmp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (list[j] > list[j + 1])
            {
                tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }
        }
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

    bubble_sort(a, 10);
    print_array(a, 10);
    return 0;
}