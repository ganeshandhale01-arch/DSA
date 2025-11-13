// C program to delete first occurrence of key in singly linked list

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
    SLINK *firstLink = NULL, *firstPrev = NULL;

    if (!head || !*head)
    {
        return result;
    }

    while (cur != NULL)
    {
        if (cur->data == key)
        {
            firstPrev = prev;
            firstLink = cur;
            break;
        }
        prev = cur;
        cur = cur->next;
    }

    if (firstLink == NULL)
    {
        printf("Key not found\n");
        result = EXIT_FAILURE;
        return result;
    }
    else
    {   // if head node itself holds the key to be deleted
        if (firstPrev == NULL )
        {
            firstLink = *head;
            *head = (*head)->next;
        }
        else
        {
            firstLink = firstPrev->next;
            firstPrev->next = firstLink->next;
        }                                                                                                           
        free((void*)firstLink);
        result = EXIT_SUCCESS;
    }
    return result;
}

int main()
{
    SLINK * head = createNode(2);
    head->next = createNode(1);
    head->next->next = createNode(1);
    head->next->next->next = createNode(3);

    int key = 1;
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