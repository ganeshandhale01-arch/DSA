/**
 * 
 * Given an array of positive integers arr[] of size n, the task is to find second largest distinct element in the array.

Note: If the second largest element does not exist, return -1.

Examples:

Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.

Input: arr[] = [10, 5, 10]
Output: 5
Explanation: The largest element of the array is 10 and the second largest element is 5.

Input: arr[] = [10, 10, 10]
Output: -1
Explanation: The largest element of the array is 10 there is no second largest element.


 * @file second_largest.c
 * @brief Find second largest element in an array with single-pass algorithm
 * @author Ganesh Andhale
 * @date December 29, 2025
 * 
 * Demonstrates:
 * - Single-pass O(n) algorithm to find second largest element
 * - Handles duplicate values correctly
 * - Edge case handling for arrays with all identical elements
 */

#include <stdio.h>

#define INT_MIN (-1)   
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
 * @brief Find the second largest element in an array
 * 
 * This function traverses the array once to find the second largest distinct
 * element. It maintains two variables: max (largest) and secondMax (second largest).
 * 
 * Algorithm:
 * 1. Initialize max and secondMax to INT_MIN
 * 2. For each element:
 *    - If element > max: secondMax = max, max = element
 *    - Else if element is between secondMax and max (and not equal to max):
 *      secondMax = element
 * 3. Return secondMax
 * 
 * Time Complexity: O(n) - single pass through array
 * Space Complexity: O(1) - only two variables used
 * 
 * @param[in] arr Pointer to integer array
 * @param[in] size Number of elements in the array
 * 
 * @return Second largest element, or INT_MIN if:
 *         - Array has fewer than 2 distinct elements
 *         - All elements are identical
 *         - Array is NULL or size is 0
 * 
 * @note Function assumes array contains at least one element
 * @note Returns INT_MIN if no valid second largest exists
 * @note Handles duplicate values correctly (ignores duplicates of max)
 * 
 * @example
 * int arr[] = {12, 35, 1, 10, 34, 1};
 * int result = secondLargest(arr, 6);  // Returns: 34
 * 
 * int arr2[] = {10, 10, 10};
 * int result2 = secondLargest(arr2, 3);  // Returns: INT_MIN (no second largest)
 */
int moveZeroToEnd(int * arr, size_t size)
{
    int * ptr1 = arr;
    int * ptr2 = arr;
    int ret = 0;

    if (arr == NULL || size == 0)
    {
        ret = -1;
    }

    for(size_t i = 0; i < size; i++)
    {
        if(*ptr1 == 0)
        {   
            ptr1++;
        }
        else if(*ptr1 != 0)
        {
            int temp = *ptr1;
            *ptr1 = *ptr2;
            *ptr2 = temp;
            ptr1++;
            ptr2++;

        }
    }

    return ret;
}

/**
 * @brief Main function demonstrating second largest element finding
 * 
 * Tests the secondLargest function with three different scenarios:
 * 1. Normal array with distinct elements
 * 2. Array with duplicate values
 * 3. Array with all identical elements
 * 
 * @return 0 on successful execution
 */
int main(void) 
{
    int ret;
    
    // Test 1: Array with distinct elements
    int arr1[] = {12, 0, 1, 0, 34, 1};
    size_t size1 = ARRAY_SIZE(arr1);

    printf("=== Test 1: Normal Array ===\n");
    printf("Array: ");
    printArray(arr1, size1);
    ret = moveZeroToEnd(arr1, size1);
    if (ret == 0)
    {   
        printf("Array after moving zeros to end: ");
        printArray(arr1, size1);
    }
    else
    {
        printf("Error in moving zeros to end\n");
    }
    
    return 0;
}
