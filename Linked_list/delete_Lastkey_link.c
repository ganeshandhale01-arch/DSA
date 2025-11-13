// C program to delete last occurrence of key in singly linked list

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
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
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

int deleteKeyOccurance (SLINK **head, int key)
{
    int result = EXIT_FAILURE;
    SLINK *cur = *head, *prev = NULL;
    SLINK *lastLink = NULL, *lastPrev = NULL;

    if (!head || !*head)
    {
        return result;
    }

    while (cur != NULL)
    {
        if (cur->data == key)
        {
            lastPrev = prev;
            lastLink = cur;
        }
        prev = cur;
        cur = cur->next;
    }

    if (lastLink == NULL)
    {
        printf("Key not found\n");
        result = EXIT_FAILURE;
        return result;
    }
    else
    {   // if head node itself holds the key to be deleted
        if (lastPrev == NULL )
        {
            lastLink = *head;
            *head = (*head)->next;
        }
        else
        {
            lastLink = lastPrev->next;
            lastPrev->next = lastLink->next;
        }                                                                                                           
        free((void*)lastLink);
        result = EXIT_SUCCESS;
    }
    return result;
}

int main()
{
    SLINK * head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    //head->next->next->next = createNode(3);

    int key = 4;
    printf("Original list: ");
    printList(head);

    int result = deleteKeyOccurance (&head, key);
    if (result == 0)
    {
        printf("key %d deleted successfully\n", key);
    }
    else
    {
        printf("key %d not found\n", key);
    }
    printf("Modified list: ");
    printList(head);

    return 0;
}