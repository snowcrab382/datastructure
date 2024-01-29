#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct
{
    element *data;
    int top;
    int capacity;
} StackType;

void init_stack(StackType *s)
{
    s->top = -1;
    s->capacity = 1;
    s->data = (element *)malloc(s->capacity * sizeof(element));
}

int is_empty(StackType *s)
{
    return s->top == -1;
}

int is_full(StackType *s)
{
    return (s->top == (s->capacity - 1));
}

void push(StackType *s, element item)
{
    if (is_full(s))
    {
        s->capacity *= 2;
        s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
    }
    s->data[++(s->top)] = item;
}

element pop(StackType *s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "스택이 비어있습니다.\n");
        exit(1);
    }
    return s->data[s->top--];
}

element peek(StackType *s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "스택이 비어있습니다.peek\n");
        exit(1);
    }
    return s->data[s->top];
}

int main(void)
{
    StackType s1;
    printf("%p\n", &s1);
    init_stack(&s1);
    printf("%p\n", &s1);
    push(&s1, 1);
    printf("%d\n", peek(&s1));
    printf("%d\n", pop(&s1));
    push(&s1, 2);
    push(&s1, 3);
    push(&s1, 4);
    push(&s1, 5);
    printf("%d\n", pop(&s1));
    printf("%d\n", pop(&s1));
    printf("%d\n", pop(&s1));
    printf("%d\n", pop(&s1));
    printf("%d\n", pop(&s1)); //empty에러 발생
    free(s1.data);
    printf("%p", &s1);
    return 0;
}