// C program to delete the occurrence 
// of key in singly linked list

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
    SLINK *cur = *head, *prev = NULL, * temp = NULL;

    // if head node itself holds the key to be deleted
    while (cur != NULL)
    {
        if (cur->data == key)
        {
            if (prev == NULL)
            {
                *head = cur->next;   
            }
            else
            {
                prev->next = cur->next;
            }
            temp = cur;
            free((void*)temp);
            result = EXIT_SUCCESS;            
        }
        else
        {
            prev = cur;
        }
        cur = cur->next;
    }
    return result;
}

int main()
{
    SLINK * head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(1);
    head->next->next->next = createNode(1);

    int key = 2;
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