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

SLINK * deleteMiddleSlink(SLINK * head1)
{
    SLINK *slowPtr = head1;
    SLINK *fastPtr = head1;
    SLINK *prev = NULL;

    if (slowPtr == NULL)
    {
        printf("The list is empty\n");
        return NULL;
    }

    if (slowPtr->next == NULL)
    {
        slowPtr = NULL;
        free(slowPtr);
        return NULL;
    }
    

    while (fastPtr != NULL && fastPtr->next != NULL)
    {
        prev = slowPtr;
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    if (prev != NULL && slowPtr != NULL) {
        prev->next = slowPtr->next;
        free(slowPtr);
        return head1;
    }
    return NULL;
}

int main()
{
    SLINK * head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);
    head1->next->next->next->next = createNode(5);

    printf("Original 1st list: ");
    printList(head1);

    head1 = deleteMiddleSlink(head1);

    printf("Deleted middle element from 1st list: ");
    printList(head1);

    SLINK * head2 = createNode(10);

    printf("Original 2nd list: ");
    printList(head2);

    head2 = deleteMiddleSlink(head2);

    printf("deleted middle element form 2nd list: ");
    printList(head2);
    
    SLINK * head3 = NULL;

    printf("Original 3rd list: ");
    printList(head3);

    head3 = deleteMiddleSlink(head3);
    
    printf("Deleted middle element from 3rd list: ");
    printList(head3);
    return 0;
}