#include <stdio.h>
#include <stdlib.h>

/**
 * @struct sLink
 * @brief Node for a singly linked list storing an int and pointer to next node.
 */
struct sLink {
    int data;           /**< integer payload */
    struct sLink* next; /**< pointer to next node, or NULL */
    struct sLink* random; /**< pointer to any node in the list or NULL */
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
 * @brief Clone a linked list with next and random pointers.
 *
 * Creates a deep copy of a linked list where each node has a next pointer
 * and a random pointer that can point to any node in the list or NULL.
 *
 * @param head Pointer to the head of the original list.
 * @return Pointer to the head of the cloned list (NULL on failure).
 */ 
SLINK* cloneList(SLINK* head) {
    if (head == NULL) return NULL;

    SLINK* cur = head;
    // Step 1: Create new nodes and insert them after original nodes
    while (cur != NULL) {
        SLINK* newNode = createNode(cur->data);
        newNode->next = cur->next;
        cur->next = newNode;
        cur = newNode->next;
    }

    // Step 2: Set random pointers for the cloned nodes
    cur = head;
    while (cur != NULL) {
        if (cur->random != NULL) {
            cur->next->random = cur->random->next;
        }
        cur = cur->next->next;
    }

    // Step 3: Separate the cloned list from the original list
    cur = head;
    SLINK* clonedHead = head->next;
    SLINK* clonedCur = clonedHead;

    while (cur != NULL) {
        cur->next = cur->next->next;
        if (clonedCur->next != NULL) {
            clonedCur->next = clonedCur->next->next;
        }
        cur = cur->next;
        clonedCur = clonedCur->next;
    }

    return clonedHead;
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
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->random = head->next->next; // 1's random points to 3
    head->next->random = head;        // 2's random points to 1 
    head->next->next->random = head->next->next->next; // 3's random points to 4
    head->next->next->next->random = head->next; // 4's random points to 2

    printf("Original list: ");
    printList(head);

    // Cloning logic would go here
    SLINK* clonedHead = cloneList(head);
    
    printf("Cloned list: ");
    printList(clonedHead); // This should print the cloned list instead

    return 0;
}

