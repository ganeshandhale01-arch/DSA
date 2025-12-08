/*************************************************************************************
 * @file Palindrome_link_rec.c
 * @brief Check if a linked list is palindrome using recursive two-pointer approach.
 *
 * This program uses a recursive algorithm to check if a singly linked list forms
 * a palindrome. The algorithm uses two pointers:
 *  - left pointer: advances forward during recursion unwinding
 *  - right pointer: advances forward during recursion (reaches end first)
 *
 * During stack unwinding, nodes are compared from outside-in, which is the
 * natural palindrome checking pattern.
 *
 * Time Complexity: O(n) - visits each node once
 * Space Complexity: O(n) - recursion stack depth equals list length
 *
 * @note The original head pointer remains unchanged after palindrome check.
 ************************************************************************************/

#include <stdbool.h> 
#include <stdio.h> 
#include <stdlib.h> 

/**
 * @struct node
 * @brief Node structure for singly linked list storing a character.
 */
struct node 
{ 
    char data;           /**< Character payload stored in node */
    struct node* next;   /**< Pointer to next node, or NULL if last node */
}; 

/**
 * @brief Recursive helper function to check palindrome by comparing from both ends.
 *
 * This function uses recursion to reach the end of the list (via right pointer),
 * then compares nodes from outside-in during stack unwinding. The left pointer
 * is shared across all recursion levels via double pointer, allowing it to
 * advance forward as the recursion unwinds.
 *
 * Algorithm:
 *  1. Base case: if right is NULL, reached end of list, return true
 *  2. Recurse to next node: move right forward
 *  3. On unwinding: compare right node's data with left node's data
 *  4. After comparison: move left forward for next level's comparison
 *  5. Return false if any comparison fails, true if all match
 *
 * @param left Pointer to pointer of left node (shared across recursion levels).
 *             Gets advanced forward during unwinding to enable outside-in comparison.
 * @param right Pointer to right node (moves forward during recursion).
 * @return true if the sub-list from left to right is palindrome, false otherwise.
 *
 * @note The double pointer for 'left' ensures all recursion levels share the
 *       same left pointer, which gets updated as recursion unwinds.
 */
bool isPalindromeUtil(struct node** left, struct node* right) 
{ 
    /* Base case: reached end of list, start comparing on return path */
    if (right == NULL) 
        return true; 

    /* Recurse to end of list - right pointer moves forward naturally */
    bool isp = isPalindromeUtil(left, right->next); 
    
    /* Early exit optimization: if sub-list already failed, no need to continue */
    if (isp == false) 
        return false; 

    /* Compare current left and right nodes (happens during stack unwinding) */
    bool isp1 = (right->data == (*left)->data); 

    /* Move left pointer forward for next comparison level
     * This modification is shared across all recursion levels via double pointer */
    *left = (*left)->next; 

    return isp1; 
} 

/**
 * @brief Check if a linked list is a palindrome.
 *
 * This is a wrapper function that initiates the recursive palindrome check.
 * It creates a local copy of the head pointer to pass to the recursive helper,
 * ensuring the original head pointer in the caller remains unchanged.
 *
 * @param head Pointer to the head of the list to check.
 * @return true if the list is a palindrome, false otherwise.
 *
 * @note Uses a local temporary variable to avoid modifying the caller's head pointer.
 */
bool isPalindrome(struct node* head) 
{ 
    struct node* left = head;  /* Create local copy to avoid modifying caller's head */
    return isPalindromeUtil(&left, head); 
} 

/**
 * @brief Insert a new node at the beginning of the list.
 *
 * Allocates a new node, sets its data, and inserts it at the head position.
 * Updates the head pointer to point to the newly inserted node.
 *
 * @param head_ref Double pointer to the head of the list (allows head modification).
 * @param new_data Character data to store in the new node.
 *
 * @note This function modifies the head pointer, so double pointer is required.
 * @warning No error checking for malloc failure in this implementation.
 */
void push(struct node** head_ref, char new_data) 
{ 
    /* Allocate memory for new node */
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
    
    /* Set node data and link to current head */
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    
    /* Update head to point to new node */
    (*head_ref) = new_node; 
} 

/**
 * @brief Print the linked list to stdout.
 *
 * Traverses the list from head to end, printing each node's data
 * in the format: data->data->...->NULL
 *
 * @param ptr Pointer to the head of the list (may be NULL for empty list).
 */
void printList(struct node* ptr) 
{ 
    while (ptr != NULL) 
    { 
        printf("%c->", ptr->data); 
        ptr = ptr->next; 
    } 
    printf("NULL\n"); 
} 

/**
 * @brief Driver program to demonstrate palindrome checking.
 *
 * This program builds a linked list by pushing characters from a string
 * one at a time, checking for palindrome after each insertion. Since push()
 * inserts at the head, the string "abacaba" results in a reversed list.
 *
 * Process:
 *  - Push 'a': List = a->NULL (palindrome)
 *  - Push 'b': List = b->a->NULL (not palindrome)
 *  - Push 'a': List = a->b->a->NULL (palindrome)
 *  - And so on...
 *
 * @return 0 on successful execution.
 */
int main() 
{ 
    struct node* head = NULL; 
    char str[] = "abacaba"; 
    int i; 

    /* Build list by pushing each character and check palindrome after each push */
    for (i = 0; str[i] != '\0'; i++) 
    { 
        push(&head, str[i]); 
        printList(head); 
        
        /* Check and print palindrome status */
        if (isPalindrome(head))
        {
            printf("Is Palindrome\n\n");
        }
        else
        {
            printf("Not Palindrome\n\n");
        }
    } 

    /* Cleanup: Free all allocated nodes (optional but good practice) */
    struct node* current = head;
    struct node* next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    return 0; 
}