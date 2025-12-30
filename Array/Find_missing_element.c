/**
 * Given an array arr[] of size n-1 with distinct integers in the range of [1, n]. This array represents a permutation of the integers from 1 to n with one element missing. Find the missing element in the array.

Examples: 

Input: arr[] = [8, 2, 4, 5, 3, 7, 1]
Output: 6
Explanation: All the numbers from 1 to 8 are present except 6.

Input: arr[] = [1, 2, 3, 5]
Output: 4
Explanation: Here the size of the array is 4, so the range will be [1, 5]. The missing number between 1 to 5 is 4

 * 
 * @file Find_missing_element.c
 * @brief Find missing element in consecutive integer sequence using sum formula
 * @author Ganesh Andhale
 * @date December 29, 2025
 * 
 * Problem Statement:
 * Given an array containing n distinct numbers from 1 to n+1, find the one
 * number that is missing from the sequence.
 * 
 * Demonstrates:
 * - Mathematical approach using sum formula: Sum = n*(n+1)/2
 * - O(n) time complexity with O(1) space complexity
 * - Integer overflow prevention using proper data types
 */

#include <stdio.h>
#include <stdint.h>

/**
 * @brief Macro to calculate the number of elements in an array
 * @param arr Array name
 * @return Number of elements in the array
 */
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/**
 * @brief Inline function to print array elements
 * 
 * Prints each element of the array separated by spaces, followed by newline.
 * 
 * @param[in] arr Array to print
 * @param[in] size Number of elements in the array
 */
static inline void printArray(const int *arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief Find the missing element in a consecutive integer sequence
 * 
 * This function finds the missing number in an array containing n distinct
 * numbers taken from the range 1 to n+1.
 * 
 * Algorithm:
 * 1. Calculate expected sum of numbers from 1 to (n+1) using formula:
 *    Sum = (n+1) * (n+2) / 2
 * 2. Calculate actual sum by iterating through array
 * 3. Missing element = Expected sum - Actual sum
 * 
 * Mathematical Basis:
 * - For sequence 1 to n: Sum = n*(n+1)/2
 * - For sequence 1 to (n+1): Sum = (n+1)*(n+2)/2
 * 
 * Time Complexity: O(n) - single pass through array
 * Space Complexity: O(1) - constant extra space
 * 
 * @param[in] arr Pointer to integer array containing n elements from range [1, n+1]
 * @param[in] size Number of elements in the array (n)
 * 
 * @return The missing element from the sequence, or -1 on error
 * 
 * @note Array must contain distinct integers from 1 to n+1 with one missing
 * @note Uses long long to prevent integer overflow for large arrays
 * @note Assumes array elements are positive integers
 * @note Returns -1 if arr is NULL or size is 0
 * 
 * @warning For very large arrays (size > 10^9), consider using XOR approach
 *          to avoid potential overflow issues
 * 
 * @example
 * int arr[] = {1, 2, 3, 5};  // Missing: 4
 * int missing = findMissingElement(arr, 4);  // Returns: 4
 * 
 * int arr2[] = {8, 2, 4, 5, 3, 7, 1};  // Missing: 6
 * int missing2 = findMissingElement(arr2, 7);  // Returns: 6
 */
int findMissingElement(int * arr, size_t size)
{
    int ret = -1;

    // Boundary condition checks
    if (arr != NULL && size != 0)
    {
        // Use long long to prevent overflow for large arrays
        unsigned long long actualTotal = 0;
        unsigned long long n = (unsigned long long)size;
        unsigned long long expectedTotal = ((n + 1) * (n + 2)) / 2;

        // Calculate actual sum
        for (size_t i = 0; i < size; i++)
        {
            actualTotal += (unsigned long long)arr[i];
        }

        ret = (int)(expectedTotal - actualTotal);
    }

    return ret;
}

/**
 * @brief Main function demonstrating missing element detection
 * 
 * Tests the findMissingElement function with two scenarios:
 * 1. Array with missing element in middle of sequence
 * 2. Array with missing element at end of sequence
 * 
 * @return 0 on successful execution
 */
int main(void) 
{
    int ret;
    
    // Test 1: Missing element in middle (missing 6)
    int arr1[] = {8, 2, 4, 5, 3, 7, 1};
    size_t size1 = ARRAY_SIZE(arr1);

    printf("=== Test 1: Missing Element in Middle ===\n");
    printf("Array: ");
    printArray(arr1, size1);
    ret = findMissingElement(arr1, size1);
    if (ret != -1)
    {
        printf("Missing Element: %d\n", ret);
        printf("Expected sequence: 1 to %zu\n\n", size1 + 1);
    }
    else
    {
        printf("Error: Invalid input\n\n");
    }

    // Test 2: Missing element (missing 4)
    int arr2[] = {1, 2, 3, 5};
    size_t size2 = ARRAY_SIZE(arr2);

    printf("=== Test 2: Missing Element ===\n");
    printf("Array: ");
    printArray(arr2, size2);
    ret = findMissingElement(arr2, size2);
    if (ret != -1)
    {
        printf("Missing Element: %d\n", ret);
        printf("Expected sequence: 1 to %zu\n", size2 + 1);
    }
    else
    {
        printf("Error: Invalid input\n");
    }

    return 0;
}
