#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
    element array[MAX_LIST_SIZE];
    int size;
} ArrayList;

void init(ArrayList *L)
{
    L->size = 0;
}

int is_empty(ArrayList *L)
{
    return L->size == 0;
}

int is_full(ArrayList *L)
{
    return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayList *L, int pos)
{
    if (pos < 0 || pos >= L->size)
    {
        fprintf(stderr, "잘못된 pos 입력입니다.\n");
        exit(1);
    }
    return L->array[pos];
}

void insert_last(ArrayList *L, element item)
{
    if (L->size >= MAX_LIST_SIZE)
    {
        fprintf(stderr, "리스트에 빈 공간이 없습니다.\n");
        exit(1);
    }
    L->array[(L->size)++] = item;
}

void insert(ArrayList *L, int pos, element item)
{
    if (!is_full(L) && pos >= 0 && pos <= L->size)
    {
        for (int i = (L->size - 1); i >= pos; i--)
        {
            L->array[i+1] = L->array[i];
        }
        L->array[pos] = item;
        L->size++;
    }
}

element delete(ArrayList *L, int pos)
{   
    element item;
    if (pos < 0 || pos >= L->size)
    {
        fprintf(stderr, "올바르지 않은 pos 입력입니다.\n");
        exit(1);
    }
    item = L->array[pos];

    for (int i = pos; i < (L->size - 1); i++)
    {
        L->array[i] = L->array[i+1];
    }
    L->size--;
    return item;
}

int main(void)
{
    ArrayList l;
    init(&l);

    insert_last(&l, 1);
    insert(&l, 1, 3);
    insert(&l, 1, 2);
    printf("%d, %d, %d\n", get_entry(&l, 0), get_entry(&l, 1), get_entry(&l, 2));
    delete(&l, 1);
    printf("%d, %d\n", get_entry(&l, 0), get_entry(&l, 1));

    return 0;
}
