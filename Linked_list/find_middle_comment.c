/*************************************************************************************
 * @file find_middle.c
 * @brief Find the middle node of a singly linked list using slow/fast pointers.
 *
 * Provides:
 *  - createNode()       : allocate and initialize a node
 *  - printList()        : print list contents
 *  - middleSlinkData()  : return pointer to middle node (slow/fast technique)
 *
 * Notes:
 *  - middleSlinkData() returns the second middle for even-length lists (standard
 *    slow/fast behavior where fast advances by two and slow by one).
 *  - Functions return NULL or print messages when input is empty/invalid.
 ************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct sLink {
    int data;
    struct sLink* next;
};

typedef struct sLink SLINK;

/**
 * @brief Allocate and initialize a new list node.
 *
 * Allocates memory for a new SLINK, sets its data and next fields.
 *
 * @param data Integer value to store in the node.
 * @return SLINK* Pointer to the newly allocated node, or NULL on failure.
 */
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

/**
 * @brief Print the linked list to stdout.
 *
 * Prints nodes in the format "val -> " and terminates with "NULL\n".
 *
 * @param head Pointer to the head of the list (may be NULL).
 */
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

/**
 * @brief Find and return the middle node of a singly linked list.
 *
 * Uses the slow/fast pointer technique:
 *  - slow advances by one node, fast advances by two nodes.
 *  - when fast reaches end (NULL) or has no next, slow points to middle.
 *
 * For even-length lists this returns the second of the two middle nodes.
 *
 * @param head1 Pointer to head of the list.
 * @return SLINK* Pointer to the middle node, or NULL if list is empty.
 */
SLINK * middleSlinkData(SLINK * head1)
{
    SLINK *slowPtr = head1;
    SLINK *fastPtr = head1;

    if (slowPtr == NULL)
    {
        /* if: list is empty ? nothing to find; inform caller by returning NULL. */
        printf("The list is empty\n");
        return NULL;
    }

    /* Advance fast by 2 and slow by 1 until fast reaches end; slow then at middle. */
    while (fastPtr != NULL && fastPtr->next != NULL)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    /* else: slowPtr points to middle node; return it. */
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
        /* if: middle found ? print value. */
        printf("The lists middle element = %d\n", middleptr->data);
    }
    else
    {
        /* else: no middle because list empty ? inform user. */
        printf("The lists has a no element.\n");
    }

    SLINK * head2 = createNode(10);

    printf("Original 1st list: ");
    printList(head2);

    middleptr = middleSlinkData(head2);
    if (middleptr != NULL)
    {
        /* if: middle found ? print value. */
        printf("The lists middle element = %d\n", middleptr->data);
    }
    else
    {
        /* else: no middle because list empty ? inform user. */
        printf("The lists has a no element.\n");
    }

    SLINK * head3 = NULL;

    printf("Original 1st list: ");
    printList(head3);

    middleptr = middleSlinkData(head3);
    if (middleptr != NULL)
    {
        /* if: middle found ? print value. */
        printf("The lists middle element = %d\n", middleptr->data);
    }
    else
    {
        /* else: no middle because list empty ? inform user. */
        printf("The lists has a no element.\n");
    }

    return 0;
}