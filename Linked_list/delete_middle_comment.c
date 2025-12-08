/*************************************************************************************
 * @file delete_middle.c
 * @brief Delete the middle node of a singly linked list using slow/fast pointers.
 *
 * Provides:
 *  - createNode()         : allocate and initialize a node
 *  - printList()          : print list contents
 *  - deleteMiddleSlink()  : delete middle node (slow/fast technique)
 *
 * Notes:
 *  - deleteMiddleSlink() returns updated head after deleting the middle node.
 *  - For even-length lists, deletes the second of the two middle nodes.
 *  - Returns NULL if list is empty or only has one node (after deletion).
 ************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/**
 * @struct sLink
 * @brief Node for a singly linked list storing an integer and pointer to next.
 */
struct sLink {
    int data;           /**< integer payload */
    struct sLink* next; /**< pointer to next node or NULL */
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
 * @brief Delete the middle node of a singly linked list.
 *
 * Uses the slow/fast pointer technique:
 *  - slow advances by one node, fast advances by two nodes.
 *  - prev tracks the node before slow.
 *  - when fast reaches end, slow points to middle; delete it via prev->next.
 *
 * For even-length lists, deletes the second of the two middle nodes.
 *
 * @param head1 Pointer to head of the list.
 * @return SLINK* Updated head pointer, or NULL if list becomes empty.
 */
SLINK * deleteMiddleSlink(SLINK * head1)
{
    SLINK *slowPtr = head1;
    SLINK *fastPtr = head1;
    SLINK *prev = NULL;

    if (slowPtr == NULL)
    {
        /* if: list is empty ? nothing to delete; return NULL. */
        printf("The list is empty\n");
        return NULL;
    }

    if (slowPtr->next == NULL)
    {
        /* if: only one node in list ? delete it and return NULL (list becomes empty). */
        slowPtr = NULL;
        free(slowPtr);
        return NULL;
    }
    

    /* Advance fast by 2 and slow by 1; prev tracks node before slow. */
    while (fastPtr != NULL && fastPtr->next != NULL)
    {
        prev = slowPtr;
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    if (prev != NULL && slowPtr != NULL) {
        /* if: middle node found (slowPtr) with valid prev ? remove slowPtr from list and free. */
        prev->next = slowPtr->next;
        free(slowPtr);
        return head1;
    }
    /* else: unexpected case (shouldn't happen with valid input) ? return NULL. */
    return NULL;
}

/**
 * @brief Program entry point demonstrating middle node deletion.
 *
 * Tests deleteMiddleSlink() on lists of different lengths (5, 1, 0 nodes).
 *
 * @return int 0 on success.
 */
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

    printf("Deleted middle element from 2nd list: ");
    printList(head2);
    
    SLINK * head3 = NULL;

    printf("Original 3rd list: ");
    printList(head3);

    head3 = deleteMiddleSlink(head3);
    
    printf("Deleted middle element from 3rd list: ");
    printList(head3);
    return 0;
}