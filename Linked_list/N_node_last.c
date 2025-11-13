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

int findNthNode (SLINK * head, int N)
{
    int result = -1;
    SLINK *cur = head;
    int count = 1;

    if ((N > 0) && (head != NULL))
    {
        while (cur != NULL && count < N)
        {
            count++;
            cur = cur->next;
        }
        result = (cur != NULL) ? cur->data : -1;
    }

    return result;
}

int findNthNodeTail (SLINK * head, int N)
{
    int result = -1;
    SLINK *fastptr = head, *slowptr = head;

    if ((N > 0) && (head != NULL))
    {
        for (int i = 1; i < N; i++)
        {
            fastptr = fastptr->next;
            if (fastptr == NULL)
            {
                break;
            }
        }

        while (fastptr != NULL && fastptr->next != NULL)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next;
        }

        result = (fastptr !=NULL) ? slowptr->data : -1;
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
        printf("%dth is large/less than the number of nodes in the list\n", N);
    }
    else
    {
        printf("%dth node data is %d \n",N, result);
    }
    result = findNthNodeTail(head, N);
    if (result == -1)
    {
        printf("%dth is large/less than the number of nodes in the list\n", N);
    }
    else
    {
        printf("%dth node from tail data is %d \n",N, result);
    }

    return 0;
}