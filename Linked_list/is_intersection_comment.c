/**
 * @file is_intersection.c
 * @brief Detect whether two singly linked lists intersect (share a node).
 *
 * Simple singly-linked list utilities and an intersection checker that compares
 * tail nodes and, if equal, aligns list starts to find intersection.
 *
 * Functions return 1 if intersection exists, 0 otherwise.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @struct sLink
 * @brief Node for a singly linked list storing an integer and pointer to next node.
 */
struct sLink {
    int data;           /**< integer payload */
    struct sLink* next; /**< pointer to next node or NULL */
};

typedef struct sLink SLINK;

/**
 * @brief Allocate and initialize a new node.
 * @param data value to store in node
 * @return pointer to new node or NULL on allocation failure
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
 * @brief Print the linked list to stdout in "val -> " format ending with "NULL".
 * @param head pointer to head node (may be NULL)
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
 * @brief Check if two singly linked lists intersect.
 *
 * Approach:
 *  - If either list is empty -> no intersection.
 *  - Walk to tails; if tails differ -> no intersection.
 *  - If tails equal, there is an intersection (lists share nodes).
 *
 * @param head1 pointer to first list head
 * @param head2 pointer to second list head
 * @return 1 if lists intersect, 0 otherwise
 */
int isIntersection(SLINK * head1, SLINK *head2)
{
    SLINK *ptr1 = head1;
    SLINK *ptr2 = head2;

    if (ptr1 == NULL || ptr2 == NULL)
    {
        /* If either list is empty there cannot be a shared node -> no intersection. */
        printf("No intersection (one or both lists are empty)\n");
        return 0;
    }

    /* Advance to tail of first list */
    while (ptr1->next != NULL)
    {
        ptr1 = ptr1->next;
    }

    /* Advance to tail of second list */
    while (ptr2->next != NULL)
    {
        ptr2 = ptr2->next;
    }
    
    if (ptr1 == ptr2)
    {
        /* Tails are the same node -> lists intersect (share at least one node). */
        return 1;
    }
    else
    {
        /* Different tail nodes -> no intersection (lists are disjoint). */
        return 0;
    }
}

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

    result = isIntersection(head1, head2);
    if (result == 1)
    {
        /* Intersection detected: at least one common node exists between lists. */
        printf("The lists intersect.\n");
    }
    else
    {
        /* No intersection detected: lists do not share any node. */
        printf("The lists do not intersect.\n");
    }

    return 0;
}