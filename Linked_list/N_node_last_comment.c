// C program to delete the occurrence of key in singly linked list
/**
 * @file N_node_last.c
 * @brief Linked-list utilities: create/print list, find Nth node from head and from tail.
 *
 * Provides:
 *  - createNode()      : allocate and initialize a node
 *  - printList()       : print list contents
 *  - findNthNode()     : find Nth node from head (1-based)
 *  - findNthNodeTail() : find Nth node from tail (1-based) using two-pointer method
 *
 * Notes:
 *  - Functions return -1 to indicate invalid N or N larger than list length.
 *  - Code logic unchanged; only documentation/comments added.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @struct sLink
 * @brief Node for a singly linked list storing an integer and pointer to next node.
 */
struct sLink {
    int data;
    struct sLink* next;
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
        /* Allocation failed: return NULL for caller to handle. */
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
 * @brief Return data of Nth node from head (1-based).
 * @param head pointer to list head
 * @param N 1-based index
 * @return node data or -1 if N is invalid or list too short
 */
int findNthNode (SLINK * head, int N)
{
    int result = -1;
    SLINK *cur = head;
    int count = 1;

    /* Validate inputs: N must be > 0 and list must be non-empty. */
    if ((N > 0) && (head != NULL))
    {
        while (cur != NULL && count < N)
        {
            count++;
            cur = cur->next;
        }
        /* If cur is NULL here then N > length -> return -1, else return data. */
        result = (cur != NULL) ? cur->data : -1;
    }

    return result;
}

/**
 * @brief Return data of Nth node from tail (1-based).
 *
 * Uses a two-pointer technique:
 *  - advance fastptr up to N-1 steps (implementation protects against NULL in loop)
 *  - then move both pointers until fastptr reaches the end; slowptr is Nth from tail
 *
 * @param head pointer to head of list
 * @param N 1-based index from tail
 * @return node data or -1 if N is invalid or list too short
 */
int findNthNodeTail (SLINK * head, int N)
{
    int result = -1;
    SLINK *fastptr = head, *slowptr = head;

    /* Validate inputs: N must be > 0 and list must be non-empty. */
    if ((N > 0) && (head != NULL))
    {
        /* Advance fastptr N-1 times; if it becomes NULL we break and handle below. */
        for (int i = 1; i < N; i++)
        {
            fastptr = fastptr->next;
            if (fastptr == NULL)
            {
                /* Reached end before completing N-1 advances: N may be > length. */
                break;
            }
        }

        /* Move both pointers until fastptr reaches the last node.
         * After the loop, slowptr points to the Nth node from tail if fastptr valid.
         */
        while (fastptr != NULL && fastptr->next != NULL)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next;
        }

        /* If fastptr is non-NULL we consider slowptr valid; otherwise return -1. */
        result = (fastptr != NULL) ? slowptr->data : -1;
    }

    return result;
}

int main()
{
    int N = 2;
    int result = -1;
    SLINK * head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    printf("Original list: ");
    printList(head);

    result = findNthNode(head, N);
    if (result == -1)
    {
        /* if: result == -1 -> either N is invalid (<=0) or N is larger than the number of nodes.
         * Inform the user that the requested position is out of bounds.
         */
        printf("%dth is large/less than the number of nodes in the list\n", N);
    }
    else
    {
        /* else: valid Nth node found from head; print its data. */
        printf("%dth node data is %d \n",N, result);
    }

    result = findNthNodeTail(head, N);
    if (result == -1)
    {
        /* if: result == -1 -> either N is invalid (<=0) or N is larger than the number of nodes.
         * Inform the user that the requested position from tail is out of bounds.
         */
        printf("%dth is large/less than the number of nodes in the list\n", N);
    }
    else
    {
        /* else: valid Nth node found from tail; print its data. */
        printf("%dth node from tail data is %d \n",N, result);
    }

    return 0;
}