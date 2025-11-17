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

SLINK * middleSlinkData(SLINK * head1)
{
    SLINK *slowPtr = head1;
    SLINK *fastPtr = head1;

    if (slowPtr == NULL)
    {
        printf("The list is empty\n");
        return NULL;
    }

    while (fastPtr != NULL && fastPtr->next != NULL)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    return slowPtr;
}

int main()
{
    SLINK * middleptr = NULL;   
    SLINK * head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);
    head1->next->next->next->next = createNode(5);

    printf("Original 1st list: ");
    printList(head1);

    middleptr = middleSlinkData(head1);
    if (middleptr != NULL)
    {
        printf("The lists middle element = %d\n", middleptr->data);
    }
    else
    {
        printf("The lists has a no element.\n");
    }

    SLINK * head2 = createNode(10);

    printf("Original 1st list: ");
    printList(head2);

    middleptr = middleSlinkData(head2);
    if (middleptr != NULL)
    {
        printf("The lists middle element = %d\n", middleptr->data);
    }
    else
    {
        printf("The lists has a no element.\n");
    }

    SLINK * head3 = NULL;

    printf("Original 1st list: ");
    printList(head3);

    middleptr = middleSlinkData(head3);
    if (middleptr != NULL)
    {
        printf("The lists middle element = %d\n", middleptr->data);
    }
    else
    {
        printf("The lists has a no element.\n");
    }

    return 0;
}