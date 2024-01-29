#include <stdio.h>
#include <stdlib.h>

int sorted[10];

void merge(int list[], int left, int mid, int right)
{
    int i, j, k, l;
    i = left; j = mid + 1; k = left;

    while (i <= mid && j <= right)
    {
        if (list[i] <= list[j])
        {
            sorted[k++] = list[i++];
        }
        else {
            sorted[k++] = list[j++];
        }
    }

    if (i > mid) {
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
    }
    else 
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];

    for (l = left; l <= right; l++)
        list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right)
{
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        merge_sort(list, left, mid);
        merge_sort(list, mid + 1, right);
        merge(list, left, mid, right);
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

    merge_sort(a, 0, 10);
    print_array(a, 10);

    return 0;
}