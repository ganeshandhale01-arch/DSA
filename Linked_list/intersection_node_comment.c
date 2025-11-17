/*************************************************************************************
 * @file intersection_node.c
 * @brief Find intersection node of two singly linked lists (if any).
 *
 * Simple singly-linked list utilities and a function to detect the intersection
 * node (first common node) by comparing tails and aligning starts. The
 * intersectionNode() function returns the data stored at the intersecting node
 * or 0 when there is no intersection.
 *
 * Functions:
 *  - createNode()      : allocate and initialize a node
 *  - printList()       : print list contents
 *  - intersectionNode(): find first intersecting node's data (or 0 if none)
 *
 * Return conventions:
 *  - intersectionNode(): returns intersecting node's data (non-zero) on success,
 *                        returns 0 when lists do not intersect or inputs invalid.
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
 * Allocates memory for a new SLINK, sets the data field and next to NULL.
 *
 * @param data Integer value to store in the node.
 * @return SLINK* Pointer to the newly allocated node on success, NULL on failure.
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
 * @return void
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
 * @brief Find the data value at the intersection node of two linked lists.
 *
 * Approach:
 *  1. If either list is empty -> no intersection.
 *  2. Walk to each list's tail and count nodes (len1, len2).
 *  3. If tails differ -> lists are disjoint -> return 0.
 *  4. Align the start of the longer list by the length difference.
 *  5. Advance both pointers together until they meet at the intersection node.
 *
 * @param head1 Pointer to the head of the first list.
 * @param head2 Pointer to the head of the second list.
 * @return int Data value at the intersection node, or 0 if no intersection.
 */
int intersectionNode(SLINK * head1, SLINK *head2)
{
    SLINK *ptr1 = head1;
    SLINK *ptr2 = head2;
    int len1 = 0, len2 = 0;

    if (ptr1 == NULL || ptr2 == NULL)
    {
        /* If either list is empty there cannot be a shared node -> return 0. */
        printf("No intersection (one or both lists are empty)\n");
        return 0;
    }

    /* Walk to tail of first list while counting nodes (len1). */
    while (ptr1->next != NULL)
    {
        len1++;
        ptr1 = ptr1->next;
    }

    /* Walk to tail of second list while counting nodes (len2). */
    while (ptr2->next != NULL)
    {
        len2++;
        ptr2 = ptr2->next;
    }
    
    if (ptr1 == ptr2)
    {
        /* Tails match -> lists intersect.
         * Reset pointers to list heads, set ptr1 to longer list head and ptr2 to shorter.
         * Advance ptr1 by the length difference to align both pointers equally far from tail.
         */
        ptr1 = len1 > len2 ? head1 : head2;
        ptr2 = len1 > len2 ? head2 : head1;
        int diff = len1 > len2 ? len1 - len2 : len2 - len1;
        
        /* Advance the pointer of the longer list by 'diff' nodes. */
        while (diff > 0)
        {
            ptr1 = ptr1->next;
            diff--;
        }
        
        /* Move both pointers in lock-step until they meet at the intersection node. */
        while (ptr1 != ptr2)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        /* Return the data at the intersection node. */
        return ptr1->data;
    }
    else
    {
        /* Different tails -> no intersection. */
        return 0;
    }
}

/**
 * @brief Program entry point demonstrating intersection detection.
 *
 * Builds two lists and creates an intersection for demonstration.
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

    SLINK * head2 = createNode(6);
    head2->next = head1->next->next; // Creating intersection at node with data 3

    printf("Original 1st list: ");
    printList(head1);

    printf("Original 2nd list: ");
    printList(head2);

    result = intersectionNode(head1, head2);
    if (result != 0)
    {
        /* Intersection found: print intersecting node data. */
        printf("The lists intersect at data %d\n", result);
    }
    else
    {
        /* No intersection: inform the user. */
        printf("The lists do not intersect.\n");
    }

    return 0;
}