/*************************************************************************************
 * @file Reverse_slink.c
 * @brief Reverse a singly linked list iteratively by modifying next pointers.
 *
 * Provides:
 *  - createNode()  : allocate and initialize a node
 *  - printList()   : print list contents
 *  - reverseNode() : reverse the list in-place using iterative pointer manipulation
 *
 * Notes:
 *  - reverseNode() modifies the head pointer via a double pointer (**head).
 *  - Returns EXIT_SUCCESS on success, EXIT_FAILURE if list is empty.
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
 * @brief Reverse a singly linked list in-place (iterative approach).
 *
 * Uses three pointers (prev, cur, next) to reverse the direction of next pointers:
 *  - Traverse the list, updating each node's next to point to its previous node.
 *  - Update head to point to the new first node (old tail).
 *
 * @param head Double pointer to the head of the list; updated to new head on success.
 * @return int EXIT_SUCCESS (0) if reverse succeeds, EXIT_FAILURE if list is empty/invalid.
 */
int reverseNode(SLINK ** head)
{
    SLINK *prev = NULL, *cur = *head, *next;

    if (head == NULL || *head == NULL)
    {
        /* if: list is empty or head pointer invalid ? cannot reverse; return failure. */
        printf(" lists are empty)\n");
        return EXIT_FAILURE;
    }

    /* Iterate through list, reversing next pointers:
     * - save next node before changing cur->next
     * - reverse the link: cur->next = prev
     * - advance prev and cur forward
     */
    while (cur != NULL)
    {
        next = cur->next;   /* save next node */
        cur->next = prev;   /* reverse the link */
        prev = cur;         /* move prev forward */
        cur = next;         /* move cur forward */
    }
    /* else: after loop completes, prev points to new head (old tail); update *head. */
    *head = prev;              

    return EXIT_SUCCESS;
}

/**
 * @brief Program entry point demonstrating list reversal.
 *
 * Builds a test list, prints it, reverses it, and prints the result.
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

    printf("Original list: ");
    printList(head1);

    result = reverseNode(&head1);
    if (result == 0)
    {
        /* if: reverse succeeded (EXIT_SUCCESS=0) ? print reversed list. */
        printf("Reverse list: ");
        printList(head1);
    }
    else
    {
        /* else: reverse failed (list was empty) ? inform user. */
        printf("The lists is empty.\n");
    }
    return 0;
}