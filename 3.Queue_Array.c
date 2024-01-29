#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct Queue
{
    element data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void init_queue(Queue *q) 
{
    q->front = -1;
    q->rear = -1;
}

int is_empty(Queue *q)
{
    return q->front == q->rear;
}

int is_full(Queue *q)
{
    return q->rear == (MAX_QUEUE_SIZE - 1);
}

void enqueue(Queue *q, element item)
{
    if (is_full(q)) {
        fprintf(stderr, "큐에 빈 공간이 없습니다.\n");
        exit(1);
    }
    q->data[++(q->rear)] = item;
}

element dequeue(Queue *q)
{
    if (is_empty(q)) {
        fprintf(stderr, "큐가 비어있습니다.\n");
        exit(1);
    }
    return q->data[++(q->front)];
}

int main(void) {

    Queue q;
    init_queue(&q);
    
    enqueue(&q, 1);
    printf("%d\n", dequeue(&q));
    enqueue(&q, 2);
    printf("%d\n", dequeue(&q));
    enqueue(&q, 3);
    printf("%d\n", dequeue(&q));
    enqueue(&q, 4);
    printf("%d\n", dequeue(&q));
    enqueue(&q, 5);
    printf("%d\n", dequeue(&q));

    printf("%d\n", dequeue(&q));
    return 0;
}