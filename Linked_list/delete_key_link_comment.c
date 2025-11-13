/**
 * @file delete_key_link.c
 * @brief Simple singly linked list utilities and deletion of occurrences of a key.
 *
 * Provides:
 *  - createNode() : allocate and initialize a node
 *  - printList()  : print list contents
 *  - deleteKeyOccurance() : delete all occurrences of a given key
 *
 * Example usage in main().
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @struct sLink
 * @brief Node for a singly linked list storing an int and pointer to next node.
 */
struct sLink {
    int data;           /**< integer payload */
    struct sLink* next; /**< pointer to next node, or NULL */
};

typedef struct sLink SLINK;

/**
 * @brief Create and initialize a new list node.
 *
 * Allocates memory for a new SLINK node, sets its data field and initializes
 * next to NULL.
 *
 * @param data Integer value to store in the new node.
 * @return Pointer to the newly allocated node (NULL on allocation failure).
 */
SLINK * createNode(int data)
{
    SLINK *newNode = (SLINK *)malloc(sizeof(SLINK));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/**
 * @brief Print the linked list to stdout.
 *
 * Prints each node's data in the form "val -> " and ends with "NULL\n".
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
 * @brief Delete all occurrences of key in the singly linked list.
 *
 * Traverses the list and deletes every node whose data equals key. The head
 * pointer is updated if head nodes are deleted. Frees removed nodes.
 *
 * @param head Double pointer to the head of the list. May be updated if the
 *        head node(s) are deleted.
 * @param key Integer key to delete (all occurrences).
 * @return EXIT_SUCCESS if at least one node was deleted; EXIT_FAILURE if key
 *         was not found or if the list/head is invalid.
 */
int deleteKeyOccurance (SLINK **head, int key)
{
    int result = EXIT_FAILURE;
    SLINK *cur = *head, *prev = NULL, * temp = NULL;

    if (!head || !*head)
        return result;

    /* Traverse the list. Use next pointer to safely advance after freeing. */
    while (cur != NULL)
    {
        if (cur->data == key)
        {
            /* Case: deleting current node with matching key.
             * Sub-cases:
             *  - prev == NULL : current node is the head. Update head to skip it.
             *  - prev != NULL : current node is in middle/end. Bypass it by
             *    linking prev->next to current->next.
             */
            if (prev == NULL)
            {
                /* Deleting head node: advance head to next node. */
                *head = cur->next;
            }
            else
            {
                /* Deleting non-head node: bypass current node. */
                prev->next = cur->next;
            }
            temp = cur;
            cur = cur->next;
            free((void*)temp);
            result = EXIT_SUCCESS;
            /* prev remains unchanged when we delete current, because prev still
             * points to the node before the next node to examine.
             */
        }
        else
        {
            /* Current node not deleted: move prev forward to current. */
            prev = cur;
            cur = cur->next;
        }
    }
    return result;
}

/**
 * @brief Program entry point demonstrating deletion of occurrences.
 *
 * Builds a short linked list, attempts to delete all occurrences of a
 * specified key, and prints the original and modified lists.
 *
 * @return 0 on success.
 */
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
// ...existing code...