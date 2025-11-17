// C program to delete the occurrence of key in singly linked list

#include <stdio.h>
#include <stdlib.h>

struct sLink {
    int data;
    struct sLink* next;
};

typedef struct sLink SLINK;

SLINK * createNode(int data)
{
    SLINK *newNode = (SLINK *)malloc(sizeof(SLINK));
    if (!newNode)
    {
        return NULL;
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }
}

void printList(SLINK * head)
{
    SLINK *cur = head;
    while (cur != NULL)
    {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

SLINK * reverseNode(SLINK * head)
{   
   if ((head == NULL) || (head->next == NULL))
    {
        return head;
    }

    SLINK *rest_head = reverseNode(head->next);
    SLINK * rest_tail = head->next;//head->next->next = head;
    rest_tail->next = head;
    head->next = NULL;
    return rest_head;
}

int main()
{
    SLINK * head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);

    printf("Original list: ");
    printList(head1);

    SLINK * reverse = reverseNode(head1);
    if (reverse != NULL)
    {
        printf("Reverse list: ");
        printList(reverse);
    }
    else
    {
        printf("The lists is empty.\n");
    }
    return 0;
}
