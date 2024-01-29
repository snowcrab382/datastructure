#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
    element data;
    struct Node *link;
} Node;

Node* insert_first(Node *head, element value)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = value;

    if (head == NULL)
    {
        head = p;
        p->link = head;
    }
    p->link = head->link;
    head->link = p;
    return head;
}

Node* insert_last(Node *head, element value)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = value;

    if (head == NULL)
    {
        head = p;
        p->link = head;
    }
    p->link = head->link;
    head->link = p;
    head = p; //insert_first와 다른 점은 head를 이동시키는 것 밖에 없다.
    return head;
}

void print_list(Node *head) // do~while 문을 사용함에 주의
{
    Node *p;

    if (head == NULL) return;
    p = head->link;

    do {
        printf("%d->", p->data);
        p = p->link;
    } while (p != head);
    printf("%d->\n", p->data);
}

int main(void)
{
    Node *head = NULL;
    
    head = insert_first(head, 30);
    head = insert_first(head, 20);
    head = insert_first(head, 10);
    print_list(head);

    head = insert_last(head, 40);
    head = insert_last(head, 50);
    print_list(head);
    
    return 0;
}