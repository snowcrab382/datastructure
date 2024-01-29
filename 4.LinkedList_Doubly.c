#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
    element data;
    struct DListNode *llink;
    struct DListNode *rlink;
} DListNode;

void init(DListNode *phead)
{
    phead->llink = phead;
    phead->rlink = phead;
}

void print_list(DListNode *phead)
{
    DListNode *p;
    for (p = phead->rlink; p != phead; p = p->rlink)
    {
        printf("<-| |%d| |->", p->data);
    }
    printf("\n");
}

void dinsert(DListNode *before, element data)
{
    DListNode *newNode = (DListNode *)malloc(sizeof(DListNode));
    newNode->data = data;
    newNode->llink = before;
    newNode->rlink = before->rlink;
    before->rlink->llink = newNode;
    before->rlink = newNode;
}

void ddelete(DListNode *head, DListNode *removed)
{
    if (removed == head) return;
    removed->rlink->llink = removed->llink;
    removed->llink->rlink = removed->rlink;
    free(removed);
}

int main(void)
{
    DListNode *head = (DListNode *)malloc(sizeof(DListNode)); //헤드 포인터가 아닌 헤드노드를 사용한다. 삽입/연산 구현 시 더 편리하기 때문
    init(head);

    printf("추가 단계\n");
    for (int i = 0; i < 5; i++)
    {
        dinsert(head, i);
        print_list(head);
    }

    printf("삭제 단계\n");
    for (int i = 0; i < 5; i++)
    {
        print_list(head);
        ddelete(head, head->rlink);
    }

    return 0;
}