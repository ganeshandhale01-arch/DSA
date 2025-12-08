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

int isLoop(SLINK * head1)
{
    SLINK *slowPtr = head1;
    SLINK *fastPtr = head1;
    SLINK *cur = head1;
    
    if (slowPtr == NULL || fastPtr == NULL)
    {
        printf("No intersection (one or both lists are empty)\n");
        return 0;
    }

    while (fastPtr != NULL && fastPtr->next != NULL)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr)
        {
            break;
        }
    }
    
    if (slowPtr == fastPtr)
    {
        SLINK *startOfLoop = head1; // Assuming loop starts at second node for demo
        while (slowPtr != startOfLoop)
        {
            ///printf("%d -> ", cur->data);
            startOfLoop = startOfLoop->next;
            slowPtr = slowPtr->next;
        }   
        printf("Loop detected at node with data %d\n", startOfLoop->data);
        printf("The linked list with loop is: \n");
        //print the non-loop part
        cur = head1;
        while (cur != startOfLoop)
        {
            printf("%d -> ", cur->data);
            cur = cur->next;
        }
        // print the loop part
        SLINK *loopNode = startOfLoop;
        do
        {
            printf("%d -> ", loopNode->data);
            loopNode = loopNode->next;
        } while (loopNode != startOfLoop);
        printf("Back to start loop %d\n", startOfLoop->data); // to show the loop back
        return 1;
    }
    else
    {
        while (cur != NULL)
        {
            printf("%d -> ", cur->data);
            cur = cur->next;
        }
        printf("NULL\n");
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
    head1->next->next->next->next = createNode(6);
    head1->next->next->next->next->next = createNode(7);
    head1->next->next->next->next->next->next = head1->next->next->next; // Creating loop for testing

    result = isLoop(head1);
    if (result == 1)
    {
        printf("The loop is present.\n");
    }
    else
    {
        printf("The loop  is not resent.\n");
    }

    return 0;
}