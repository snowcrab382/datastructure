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
    q->front = 0;
    q->rear = 0;
}

int is_empty(Queue *q)
{
    return q->front == q->rear;
}

int is_full(Queue *q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(Queue *q, element item)
{
    if (is_full(q)) {
        fprintf(stderr, "큐에 빈 공간이 없습니다.\n");
        exit(1);
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(Queue *q)
{
    if (is_empty(q)) {
        fprintf(stderr, "큐가 비어있습니다.\n");
        exit(1);
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

int main(void) {
    Queue q;
    init_queue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    printf("front : %d, rear : %d\n", q.front, q.rear);
    printf("%d\n", dequeue(&q));

    enqueue(&q, 5);
    printf("front : %d, rear : %d\n", q.front, q.rear);

    printf("%d\n", dequeue(&q));
    printf("front : %d, rear : %d\n", q.front, q.rear);
    printf("%d\n", dequeue(&q));
    printf("front : %d, rear : %d\n", q.front, q.rear);
    printf("%d\n", dequeue(&q));
    printf("front : %d, rear : %d\n", q.front, q.rear);
    printf("%d\n", dequeue(&q));
    printf("front : %d, rear : %d\n", q.front, q.rear);

    return 0;
}