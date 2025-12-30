/*Reverse a String In Place (or Reverse Words)
Problem Statement:
Given a string (character array) s[], reverse it in place ? i.e. without using extra memory (or minimal extra).
E.g.

s = "embedded" ? reversed as "deddebme" 
Or, a more advanced variant: reverse the words in a sentence in place.

E.g.

?the sky is blue? ? ?blue is sky the? 
Why this is common in embedded / system-level settings:

Strings are arrays of char at core ? reversing them tests pointer arithmetic, boundary handling, memory safety.
Requires careful swap logic, often in constrained environments (like no dynamic allocation).
The ?reverse words? variant adds complexity because you must do two-stage reversals (reverse full string, then reverse each word) ? a good test of algorithmic decomposition. */


/**
 * @file reverser_inplace.c
 * @brief In-place string and word reversal implementation
 * @author Ganesh Andhale
 * @date December 28, 2025
 * 
 * This file demonstrates:
 * - Character-level string reversal using XOR swap (no temp variable)
 * - Word order reversal using two-stage algorithm
 * - In-place operations with O(1) space complexity
 */

#include <stdio.h>
#include <string.h>     

/**
 * @brief Inline function to print array elements
 * 
 * Prints each character of the array separated by spaces, followed by newline.
 * 
 * @param[in] arr Array to print
 * @param[in] size Number of elements in the array
 */
static inline void printArray(const char *arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief Reverse a range of characters in a string using XOR swap
 * 
 * This function reverses characters between start and end indices (inclusive)
 * using the XOR swap technique, which requires no temporary variable.
 * 
 * XOR Swap Logic:
 * - a = a ^ b  (a now holds XOR of both)
 * - b = a ^ b  (b gets original a, since (a^b)^b = a)
 * - a = a ^ b  (a gets original b, since (a^b)^a = b)
 * 
 * Time Complexity: O(n) where n = (end - start)
 * Space Complexity: O(1)
 * 
 * @param[in,out] str Pointer to the string to reverse
 * @param[in] start Start index (inclusive)
 * @param[in] end End index (inclusive)
 * 
 * @return 0 on success, -1 if str is NULL or start >= end
 * 
 * @note Function modifies the string in place
 * @note Does not handle NULL terminator - operates on indices only
 * 
 * @example
 * char str[] = "hello";
 * reverse(str, 0, 4);  // Result: "olleh"
 * reverse(str, 0, 2);  // Result: "lle" (first 3 chars reversed)
 */
int reverse(char *str, size_t start, size_t end)
{
    int ret = -1;

    if( (str != NULL) && (start < end) )
    {
        while (start < end)
        {
            str[start] = str[start] ^ str[end];
            str[end] = str[start] ^ str[end];
            str[start] = str[start] ^ str[end];
            start++;
            end--;
        }
        ret = 0;
    }
    return ret;
}

/**
 * @brief Reverse word order in a sentence using two-stage reversal
 * 
 * This function reverses the order of words in a sentence while maintaining
 * the characters within each word. It uses a two-stage algorithm:
 * 
 * Algorithm:
 * 1. Reverse the entire string
 *    "the sky is blue" ? "eulb si yks eht"
 * 
 * 2. Reverse each individual word
 *    "eulb" ? "blue"
 *    "si" ? "is"
 *    "yks" ? "sky"
 *    "eht" ? "the"
 *    Result: "blue is sky the"
 * 
 * Time Complexity: O(n) where n is string length
 * Space Complexity: O(1) - operates in place
 * 
 * @param[in,out] str Pointer to the sentence string
 * @param[in] size Length of the string
 * 
 * @return 0 on success, -1 if size is 0 or reverse operation fails
 * 
 * @note Function modifies the string in place
 * @note Words are delimited by space character (' ')
 * @note Prints intermediate result after stage 1 for debugging
 * 
 * @example
 * char sentence[] = "the sky is blue";
 * reverseSentence(sentence, strlen(sentence));
 * // Result: "blue is sky the"
 */
int reverseSentence(char * str, size_t size)
{   
    int ret = -1;
    size_t i = 0;

    if(size != 0)
    {
        // Stage 1: Reverse entire string
        ret = reverse(str, 0, size-1);
        if (ret == 0)
            printf("After stage 1 (full reversal): %s\n", str);

        // Stage 2: Reverse each word individually
        size_t wordStart = 0;
        for (i = 0; i <= size; i++)
        {   
            // Found word boundary (space or end of string)
            if( (i == size) || (str[i] == ' ') )
            {
                if(i > wordStart)
                {
                    reverse(str, wordStart, i - 1);
                }
                wordStart = i + 1;  // Next word starts after space
            }
        }
    }

    return ret;
}

/**
 * @brief Main function demonstrating string and sentence reversal
 * 
 * Demonstrates two use cases:
 * 1. Simple character reversal: "embedded" ? "deddebme"
 * 2. Word order reversal: "the sky is blue" ? "blue is sky the"
 * 
 * @return 0 on successful execution
 */
int main()
{
    char s[] = "embedded";
    size_t size = strlen(s);
    int ret;
    
    printf("=== Test 1: Character Reversal ===\n");
    printf("Original: ");
    printArray(s, size);
    
    ret = reverse(s, 0, size-1);
    if( ret == 0)
    {
        printf("Reversed: ");
        printArray(s, size);
        printf("\n");
    }
    else
    {
        printf("Not able to reverse\n");
    }

    // Test 2: Sentence word order reversal
    char sentence[] = "the sky is blue";
    size = strlen(sentence);

    printf("=== Test 2: Word Order Reversal ===\n");
    printf("Original: %s\n", sentence);
    
    ret = reverseSentence(sentence, size);
    if(ret == 0)
    {
        printf("Final result: %s\n", sentence);
    }
    else
    {
        printf("Not able to reverse\n");
    }

    return 0;
}