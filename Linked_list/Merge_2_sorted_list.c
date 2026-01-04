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
 * @brief Merge two sorted singly linked lists into a single sorted list.
 *
 * Merges two input sorted linked lists into a new sorted linked list by
 * selecting nodes from the input lists in sorted order.
 *
 * @param head1 Pointer to the head of the first sorted list.
 * @param head2 Pointer to the head of the second sorted list.
 * @return Pointer to the head of the merged sorted list.
 */
SLINK * mergeTwoSortedLists(SLINK * head1, SLINK * head2)
{
    SLINK * mergedHead = createNode(0); // Dummy node
    SLINK * t1 = head1;
    SLINK * t2 = head2;  
    SLINK * temp = mergedHead;

    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data < t2->data)
        {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }

    temp->next = (t1 != NULL) ? t1 : t2;
    
    return mergedHead->next;
}   

/**
 * @brief Program entry point demonstrating merging of two sorted lists.
 *
 * Builds two sorted linked lists, merges them, and prints the original
 * and merged lists.
 *
 * @return 0 on success.
 */
int main()
{
    SLINK * head1 = createNode(1);
    head1->next = createNode(3);
    head1->next->next = createNode(5);
    head1->next->next->next = createNode(7);

    printf("******* Example 1 *******\n");
    printf("Original list 1 : ");
    printList(head1);

    SLINK * head2 = createNode(2);
    head2->next = createNode(4);
    head2->next->next = createNode(6);
    head2->next->next->next = createNode(8);

    printf("Original list 2 : ");
    printList(head2);

    // Merge 2 sorted lists logic would go here
    SLINK * mergedHead = mergeTwoSortedLists(head1, head2);

    printf("Merged list: ");
    printList(mergedHead); // This should print the merged list instead

    printf("******* Example 2 *******\n");
    head1 = createNode(1);
    head1->next = createNode(1);

    printf("Original list 1 : ");
    printList(head1);

    head2 = createNode(1);
    head2->next = createNode(4);

    printf("Original list 2 : ");
    printList(head2);
  
    // Merge 2 sorted lists logic would go here
    mergedHead = mergeTwoSortedLists(head1, head2);

    printf("Merged list: ");
    printList(mergedHead); // This should print the merged list instead

    return 0;
}