#include<stdio.h>
#include<stdint.h>  
#include<limits.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

struct Node * createNode(int data)
{
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node)); 
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void perintList(struct Node * head)
{
    struct Node * current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}   

int main()
{
    struct Node * head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(2);   
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next = createNode(5);

    printf("Original List size = \n: ");
    perintList(head);
    printf("\n");

    struct Node * current = head;
    while (current != NULL && current->next != NULL)
    {
        if (current->data != current->next->data)
        {
            current = current->next;
        }
        else
        {
            struct Node * temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
    }

    printf("List after removing duplicates\n: ");
    perintList(head);
    printf("\n");
}