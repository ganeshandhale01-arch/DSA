/*************************************************************************************
 * @file reverseListRecursion.c
 * @brief Reverse a singly linked list recursively by recursively reversing rest
 *        of list and adjusting next pointers.
 *
 * Provides:
 *  - createNode()  : allocate and initialize a node
 *  - printList()   : print list contents
 *  - reverseNode() : reverse the list recursively
 *
 * Notes:
 *  - reverseNode() returns the new head of the reversed list.
 *  - Returns NULL only if input is NULL (empty list).
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
 * @brief Reverse a singly linked list recursively.
 *
 * Approach:
 *  - Base case: if head is NULL or only one node, return head (already "reversed").
 *  - Recursive case: reverse the rest of the list (head->next onward), which returns
 *    the new head of the reversed sublist. Then adjust pointers so that head becomes
 *    the new tail (head->next->next = head; head->next = NULL).
 *
 * @param head Pointer to the current head of the list (or sublist).
 * @return SLINK* Pointer to the new head of the reversed list.
 */
SLINK * reverseNode(SLINK * head)
{   
   if ((head == NULL) || (head->next == NULL))
    {
        /* if: base case ? empty list or single node; return as-is. */
        return head;
    }

    /* else: recursive case ? reverse rest of list and adjust pointers. */
    SLINK *rest_head = reverseNode(head->next);  /* reverse sublist starting at head->next */
    SLINK * rest_tail = head->next;              /* the node after head becomes tail of reversed rest */
    rest_tail->next = head;                      /* make old next point back to head */
    head->next = NULL;                           /* head becomes new tail, so set next to NULL */
    return rest_head;                            /* return new head of fully reversed list */
}

int main()
{
    SLINK * head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);

    printf("Original list: ");
    printList(head1);

    SLINK * reverse = reverseNode(head1);
    if (reverse != NULL)
    {
        /* if: reverse succeeded (non-empty list) ? print reversed list. */
        printf("Reverse list: ");
        printList(reverse);
    }
    else
    {
        /* else: list was empty ? inform user. */
        printf("The lists is empty.\n");
    }
    return 0;
}