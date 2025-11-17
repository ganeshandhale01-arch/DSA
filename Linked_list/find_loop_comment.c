/*************************************************************************************
 * @file find_loop.c
 * @brief Detect and report a cycle (loop) in a singly linked list using Floyd's
 *        cycle-finding algorithm; print list (showing loop) when present.
 *
 * This file contains:
 *  - createNode(): allocate and initialize a list node.
 *  - isLoop(): detect loop, locate start of loop and print list (handles looped lists).
 *  - main(): demo runner that builds a test list and invokes isLoop().
 *
 * Return conventions:
 *  - isLoop(): returns 1 if a loop is detected, 0 otherwise.
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
 * Allocates memory for a new SLINK, initializes its data and next fields.
 *
 * @param data Value to store in the node.
 * @return SLINK* Pointer to newly allocated node, or NULL on allocation failure.
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
 * @brief Detect loop in singly linked list and print representation.
 *
 * Uses Floyd's cycle-finding algorithm (slow/fast pointers). If a loop is
 * detected, the function locates the start of the loop and prints the list
 * showing the non-loop part followed by the looped part once, and indicates
 * the loop back to the start. If no loop is present, the full linear list
 * is printed ending with "NULL".
 *
 * @param head1 Pointer to head of the list.
 * @return int 1 if loop detected, 0 otherwise.
 *
 * Brief if/else case notes:
 *  - if (slowPtr == fastPtr): meeting point found -> loop exists; proceed to
 *    locate loop start and print looped representation.
 *  - else: no meeting (fastPtr reached end) -> no loop; print linear list.
 */
int isLoop(SLINK * head1)
{
    SLINK *slowPtr = head1;
    SLINK *fastPtr = head1;
    SLINK *cur = head1;
    
    if (slowPtr == NULL || fastPtr == NULL)
    {
        /* if: list empty -> nothing to detect; no loop. */
        printf("No intersection (one or both lists are empty)\n");
        return 0;
    }

    while (fastPtr != NULL && fastPtr->next != NULL)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr)
        {
            break;
        }
    }
    
    if (slowPtr == fastPtr)
    {
        /* if: slow and fast have met -> loop detected.
         * Find start of loop by resetting a pointer to head and advancing both
         * one step at a time until they meet at the loop start.
         */
        SLINK *startOfLoop = head1; // Assuming loop starts at second node for demo
        while (slowPtr != startOfLoop)
        {
            ///printf("%d -> ", cur->data);
            startOfLoop = startOfLoop->next;
            slowPtr = slowPtr->next;
        }   
        printf("Loop detected at node with data %d\n", startOfLoop->data);
        printf("The linked list with loop is: \n");
        //print the non-loop part
        cur = head1;
        while (cur != startOfLoop)
        {
            printf("%d -> ", cur->data);
            cur = cur->next;
        }
        // print the loop part
        SLINK *loopNode = startOfLoop;
        do
        {
            printf("%d -> ", loopNode->data);
            loopNode = loopNode->next;
        } while (loopNode != startOfLoop);
        printf("Back to start loop %d\n", startOfLoop->data); // to show the loop back
        return 1;
    }
    else
    {
        /* else: no meeting point -> no loop detected; print full linear list. */
        while (cur != NULL)
        {
            printf("%d -> ", cur->data);
            cur = cur->next;
        }
        printf("NULL\n");
        return 0;
    }
}

/**
 * @brief Program entry point (demo).
 *
 * Builds a test list and inserts a loop for demonstration, then invokes isLoop().
 *
 * @return int 0 on success.
 */
int main()
{
    int result = -1;
    SLINK * head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);
    head1->next->next->next->next = createNode(6);
    head1->next->next->next->next->next = head1->next->next; // Creating loop for testing

    SLINK *head2 = createNode(10);
    head2->next = createNode(20);
    head2->next->next = createNode(30);
    head2->next->next->next = createNode(40);

    result = isLoop(head1);
    if (result == 1)
    {
        /* if: loop found -> notify user. */
        printf("The loop is present.\n");
    }
    else
    {
        /* else: no loop -> notify user. */
        printf("The loop  is not resent.\n");
    }

    result = isLoop(head2);
    if (result == 1)
    {
        /* if: loop found -> notify user. */
        printf("The loop is present.\n");
    }
    else
    {
        /* else: no loop -> notify user. */
        printf("The loop  is not resent.\n");
    }
    return 0;
}