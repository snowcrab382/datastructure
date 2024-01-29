#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct StackNode {
    element data;
    struct StackNode *link;
} StackNode;

typedef struct {
    StackNode *top;
} LinkedStackType;

void init(LinkedStackType *s)
{
    s->top = NULL;
}

int is_empty(LinkedStackType *s)
{
    return (s->top == NULL);
}

int is_full(LinkedStackType *s)
{
    return 0;
}

void push(LinkedStackType *s, element item)
{
    StackNode *tmp = (StackNode *)malloc(sizeof(StackNode));
    tmp->data = item;
    tmp->link = s->top;
    s->top = tmp;
}

element pop(LinkedStackType *s)
{
    if(is_empty(s))
    {
        fprintf(stderr, "스택이 비어있습니다.\n");
        exit(1);
    }
    StackNode *tmp = s->top;
    element data = tmp->data;
    s->top = s->top->link;
    free(tmp);
    return data;
}

void print_stack(LinkedStackType *s)
{
    StackNode *p;
    for (p = s->top; p != NULL; p = p->link)
    {
        printf("%d->", p->data);
    }
    printf("NULL\n");
}

int main(void)
{
    LinkedStackType s;
    init(&s);

    push(&s, 1); print_stack(&s);
    push(&s, 2); print_stack(&s);
    push(&s, 3); print_stack(&s);

    pop(&s); print_stack(&s);
    pop(&s); print_stack(&s);
    pop(&s); print_stack(&s);

    return 0;
}