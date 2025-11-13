// ...existing code...
/*******************************************************************************
 * @file delete_Lastkey_link.c
 * @brief Delete the last occurrence of a key in a singly linked list and demo utilities.
 *
 * Simple singly linked list utilities:
 *  - createNode() : allocate and initialize a node
 *  - printList()  : print list contents
 *  - deleteKeyOccurance() : delete the last occurrence of a given key
 *
 * Example usage in main().
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/********************************************************************************
 * @struct sLink
 * @brief Node for a singly linked list storing an int and pointer to next node.
 ********************************************************************************/
struct sLink {
    int data;           /**< integer payload */
    struct sLink* next; /**< pointer to next node, or NULL */
};

typedef struct sLink SLINK;

/*******************************************************************************
 * @brief Create and initialize a new list node.
 *
 * Allocates memory for a new SLINK node, sets its data field and initializes
 * next to NULL.
 *
 * @param data Integer value to store in the new node.
 * @return Pointer to the newly allocated node (may be NULL on allocation failure).
 *******************************************************************************/
SLINK * createNode(int data)
{
    SLINK *newNode = (SLINK *)malloc(sizeof(SLINK));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/*******************************************************************************
 * @brief Print the linked list to stdout.
 *
 * Prints each node's data in the form "val -> " and ends with "NULL\n".
 *
 * @param head Pointer to the head of the list (may be NULL).
 *******************************************************************************/
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

/********************************************************************************
 * @brief Delete the last occurrence of key in the singly linked list.
 *
 * Traverses the list to locate the last node whose data equals key, removes
 * that node from the list, frees its memory, and updates the head if needed.
 *
 * @param head Double pointer to the head of the list. May be updated if the
 *        head node is the last occurrence.
 * @param key Integer key to delete (last occurrence).
 * @return EXIT_SUCCESS if a node was deleted; EXIT_FAILURE if key was not found
 *         or if the list/head is invalid.
 ********************************************************************************/
int deleteKeyOccurance (SLINK **head, int key)
{
    int result = EXIT_FAILURE;
    SLINK *cur = *head, *prev = NULL;
    SLINK *lastLink = NULL, *lastPrev = NULL;

    if (!head || !*head)
    {
        return result;
    }

    /* Traverse the list and record the last node matching key and its previous node. */
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
        /* No node with matching key was found in the entire list.
         * Nothing to delete ? return failure.
         */
        printf("Key not found\n");
        result = EXIT_FAILURE;
        return result;
    }
    else
    {
        /* A last occurrence was found. Two cases:
         * 1) lastPrev == NULL -> the last occurrence is the head node:
         *    update head to the next node and free the old head.
         * 2) lastPrev != NULL -> the last occurrence is not the head:
         *    bypass lastLink by linking lastPrev->next to lastLink->next and free it.
         */
        if (lastPrev == NULL )
        {
            /* The recorded last occurrence has no previous node, therefore it is the head. */
            lastLink = *head;
            *head = (*head)->next;
        }
        else
        {
            /* lastPrev points to the node before lastLink. Remove lastLink by linking
             * lastPrev->next to lastLink->next.
             */
            lastLink = lastPrev->next;
            lastPrev->next = lastLink->next;
        }
        free((void*)lastLink);
        result = EXIT_SUCCESS;
    }
    return result;
}

/********************************************************************************
 * @brief Program entry point demonstrating deletion of last occurrence.
 *
 * Builds a short linked list, attempts to delete the last occurrence of a
 * specified key, and prints the original and modified lists.
 *
 * @return 0 on success.
 ********************************************************************************/
int main(void)
{
    SLINK * head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(3);

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
// ...existing code...  //