// C program to delete the occurrence of key in singly linked list

#include <stdio.h>
#include <stdlib.h>

struct sLink {
    int data;
    struct sLink* next;
};

typedef struct sLink SLINK;

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

int intersectionNode(SLINK * head1, SLINK *head2)
{
    SLINK *ptr1 = head1;
    SLINK *ptr2 = head2;
    int len1 = 0, len2 = 0;

    if (ptr1 == NULL || ptr2 == NULL)
    {
        printf("No intersection (one or both lists are empty)\n");
        return 0;
    }

    while (ptr1->next != NULL)
    {
        len1++;
        ptr1 = ptr1->next;
    }

    while (ptr2->next != NULL)
    {
        len2++;
        ptr2 = ptr2->next;
    }
    
    if (ptr1 == ptr2)
    {
        ptr1 = len1 > len2 ? head1 : head2;
        ptr2 = len1 > len2 ? head2 : head1;
        int diff = len1 > len2 ? len1 - len2 : len2 - len1;
        
        while (diff > 0)
        {
            ptr1 = ptr1->next;
            diff--;
        }
        
        while (ptr1 != ptr2)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        return ptr1->data;
    }
    else
    {
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

    result = intersectionNode(head1, head2);
    if (result != 0)
    {
        printf("The lists intersect at data %d\n", result);
    }
    else
    {
        printf("The lists do not intersect.\n");
    }

    return 0;
}