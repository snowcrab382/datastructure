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
    p->link = head;
    head = p;
    return head;
}

Node* insert(Node *head, Node *pre, element value)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

Node* delete_first(Node *head)
{
    Node *removed;
    if (head == NULL) return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

Node* delete(Node *head, Node *pre)
{
    Node *removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

void print_list(Node *head)
{
    Node *p = head;
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->link;
    }
    printf("NULL\n");
}

void get_entry(Node *head, int index)
{
    Node *p = head;
    for (int i = 0; i < index; i++)
    {
        p = p->link;
    }
    printf("%d\n", p->data);
}

Node* revert(Node *head)
{
    Node *p, *q, *r;
    p = head;
    q = NULL;
    while(p != NULL)
    {
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    return q;
}

int main(void)
{
    //단일 연결리스트 구현
    Node *head = NULL;
    
    for (int i = 0; i < 5; i++)
    {
        head = insert_first(head, i);
        print_list(head);
    }

    get_entry(head, 2); //3번째 인덱스의 값 출력

    for (int i = 0; i < 5; i++)
    {
        head = delete_first(head);
        print_list(head);
    }

    //연결리스트 역순 테스트
    Node *head1 = NULL;
    Node *head2 = NULL;

    head1 = insert_first(head1, 10);
    head1 = insert_first(head1, 20);
    head1 = insert_first(head1, 30);
    print_list(head1);

    head2 = revert(head1);
    print_list(head2);

    return 0;
}