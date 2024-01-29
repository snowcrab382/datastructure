#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode {
    element data;
    struct QueueNode *link;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} LinkedQueueType;

void init(LinkedQueueType *q)
{
    q->front = NULL;
    q->rear = NULL;
}

int is_empty(LinkedQueueType *q)
{
    return (q->front == NULL);
}

int is_full(LinkedQueueType *q)
{
    return 0;
}

void enqueue(LinkedQueueType *q, element data)
{
    QueueNode *tmp = (QueueNode *)malloc(sizeof(QueueNode));
    tmp->data = data;
    tmp->link = NULL;

    if(is_empty(q))
    {
        q->front = tmp;
        q->rear = tmp;
    }
    else {
        q->rear->link = tmp;
        q->rear = tmp;
    }
}

element dequeue(LinkedQueueType *q)
{
    QueueNode *tmp = q->front;
    element data;

    if(is_empty(q))
    {
        fprintf(stderr, "큐가 비어있습니다.\n");
        exit(1);
    }
    data = tmp->data;
    q->front = q->front->link;
    //1개의 요소만 존재할 때, rear가 NULL을 가리키도록 지정하지 않으면, 해당 요소가 메모리 해제되었을 때 rear가 가리키는 주소에 문제가 발생한다.
    //댕글링 포인터 : 해당 포인터가 가리키는 주소가 유효하지 않음에도 여전히 가리키고 있는 것
    if (q->front == NULL) 
        q->rear = NULL;
    free(tmp);
    return data;
}

void print_queue(LinkedQueueType *q)
{
    QueueNode *p;
    for (p = q->front; p != NULL; p = p->link)
    {
        printf("%d->", p->data);
    }
    printf("NULL\n");
}

int main(void)
{
    LinkedQueueType q;
    init(&q);

    enqueue(&q, 1); print_queue(&q);
    enqueue(&q, 2); print_queue(&q);
    enqueue(&q, 3); print_queue(&q);

    dequeue(&q); print_queue(&q);
    dequeue(&q); print_queue(&q);
    dequeue(&q); print_queue(&q);
    return 0;
}