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

int reverseNode(SLINK ** head)
{
    SLINK *prev = NULL, *cur = *head, *next;

    if (head == NULL || *head == NULL)
    {
        printf(" lists are empty)\n");
        return EXIT_FAILURE;
    }

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;              

    return EXIT_SUCCESS;
}

int main()
{
    int result = -1;
    SLINK * head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);

    printf("Original list: ");
    printList(head1);

    result = reverseNode(&head1);
    if (result == 0)
    {
        printf("Reverse list: ");
        printList(head1);
    }
    else
    {
        printf("The lists is empty.\n");
    }
    return 0;
}