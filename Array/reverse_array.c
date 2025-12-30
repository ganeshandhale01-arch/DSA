/**
 * 
 * Reverse an array arr[]. Reversing an array means rearranging the elements such that the first element becomes the last, the second element becomes second last and so on.

Examples:

Input: arr[] = [1, 4, 3, 2, 6, 5]
Output: [5, 6, 2, 3, 4, 1]
Explanation: The first element 1 moves to last position, the second element 4 moves to second-last and so on.

Input: arr[] = [4, 5, 1, 2]
Output: [2, 1, 5, 4]
Explanation: The first element 4 moves to last position, the second element 5 moves to second last and so on.

 * @file reverse_array.c
 * @brief In-place integer array reversal using XOR swap
 * @author Ganesh Andhale
 * @date December 29, 2025
 * 
 * Demonstrates:
 * - Array reversal without temporary variable using XOR swap
 * - O(n) time complexity with O(1) space complexity
 * - Embedded-friendly implementation (no dynamic allocation)
 */

#include <stdio.h>

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
 * @brief Reverse an integer array in place using XOR swap
 * 
 * This function reverses the elements of an array without using a temporary
 * variable. It employs the XOR swap technique which is memory-efficient.
 * 
 * XOR Swap Logic:
 * - a = a ^ b  (a now holds XOR of both values)
 * - b = a ^ b  (b becomes original a: (a^b)^b = a)
 * - a = a ^ b  (a becomes original b: (a^b)^a = b)
 * 
 * Algorithm:
 * - Use two pointers: i starting from 0, j starting from size-1
 * - Swap arr[i] and arr[j] using XOR
 * - Move i forward and j backward until they meet
 * 
 * Time Complexity: O(n/2) = O(n)
 * Space Complexity: O(1)
 * 
 * @param[in,out] arr Pointer to integer array to be reversed
 * @param[in] size Number of elements in the array
 * 
 * @return 0 on success, -1 if arr is NULL or size is 0
 * 
 * @note Function modifies the array in place
 * @note XOR swap is safe for all integer values including 0 and negative numbers
 * @note For arrays with single element, no swap is performed (i >= j condition)
 * 
 * @example
 * int arr[] = {1, 2, 3, 4, 5};
 * reverseArray(arr, 5);  // Result: {5, 4, 3, 2, 1}
 */
int reverseArray(int * arr, size_t size)
{
    int ret = -1;
    
    if( (arr != NULL) && (size != 0) )
    {
        for (size_t i = 0, j = size - 1; i < j; i++, j--)
        {
            // XOR swap - no temporary variable needed
            arr[i] = arr[i] ^ arr[j];
            arr[j] = arr[i] ^ arr[j];
            arr[i] = arr[i] ^ arr[j];
        }

        ret = 0;
    }
    return ret;
}

/**
 * @brief Main function demonstrating array reversal
 * 
 * Tests the reverseArray function with two different arrays:
 * - Array of 6 elements
 * - Array of 4 elements
 * 
 * @return 0 on successful execution
 */
int main(void) 
{
    int ret;
    
    // Test 1: Array with 6 elements
    int arr1[] = {1, 4, 3, 2, 6, 5};
    size_t size1 = ARRAY_SIZE(arr1);

    printf("=== Test 1 ===\n");
    printf("Original Array 1: ");
    printArray(arr1, size1);

    ret = reverseArray(arr1, size1);
    if (ret == 0)
    {
        printf("Array 1 Reversed: ");
        printArray(arr1, size1);
        printf("\n");
    }
    else
    {
        printf("Reverse Failed\n");
    }
        
    // Test 2: Array with 4 elements
    int arr2[] = {4, 5, 1, 2};
    size_t size2 = ARRAY_SIZE(arr2);

    printf("=== Test 2 ===\n");
    printf("Original Array 2: ");
    printArray(arr2, size2);

    ret = reverseArray(arr2, size2);
    if (ret == 0)
    {
        printf("Array 2 Reversed: ");
        printArray(arr2, size2);
    }
    else
    {
        printf("Reverse Failed\n");
    }

    return 0;
}
