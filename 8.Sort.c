#include <stdio.h>
#include <stdlib.h>

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

    return 0;
}