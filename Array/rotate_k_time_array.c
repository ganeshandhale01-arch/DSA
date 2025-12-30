/**
 * @file rotate_k_time_array.c
 * @brief Array rotation implementation using iterative approach
 * @author Ganesh Andhale
 * @date December 28, 2025
 */

#include <stdio.h>
#include <stddef.h>

/**
 * @brief Macro to calculate the number of elements in an array
 * @param arr Array name
 * @return Number of elements in the array
 */
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/**
 * @brief Macro to print array elements
 * @param arr Array to print
 * @param size Number of elements in the array
 */
#define PRINT_ARRAY(arr, size) \
    do { \
        for (int _i = 0; _i < (size); _i++) \
            printf("%d ", (arr)[_i]); \
        printf("\n"); \
    } while(0)

/**
 * @brief Rotate an array to the right by k positions
 * 
 * This function rotates the array elements to the right by k positions.
 * Each rotation moves the last element to the first position and shifts
 * all other elements one position to the right.
 * 
 * Time Complexity: O(n * k) where n is array size and k is rotations
 * Space Complexity: O(1)
 * 
 * @param[in,out] arr Pointer to the integer array to be rotated
 * @param[in] n Size of the array
 * @param[in] k Number of positions to rotate (automatically normalized if k > n)
 * 
 * @return 0 on successful rotation, -1 if rotation is not required
 * 
 * @note If k > n, the function automatically normalizes k using modulo operation
 * @note If n is 0 or k is 0 or negative, no rotation is performed
 * 
 * @example
 * int arr[] = {1, 2, 3, 4, 5};
 * rotateArray(arr, 5, 2);  // Result: {4, 5, 1, 2, 3}
 */
int rotateArray( int * arr, int n, int k)
{
    int ret = -1, i;
    int tmp;

    if ( (n != 0) && (k > 0) )
    {       
        if (k > n)
            k %= n;

        while (k--)
        {
            tmp = arr[n-1];
            for (i = n - 1; i > 0; i--)
            {
                arr[i] = arr[i-1];
            }
            arr[0] = tmp;
        }
        ret = 0;
    }

    return ret;
}

/**
 * @brief Main function to demonstrate array rotation
 * 
 * Prompts user for number of rotations and displays the array
 * before and after rotation.
 * 
 * @return 0 on successful execution
 */
int main()
{
    int n;
    int k,i;
    int arr[] = {1,2,3,4,5,6,7};

    printf("Enter the k position to rotate array\n");
    scanf("%d", &k);
    n = ARRAY_SIZE(arr);
    printf("size of array is %d & rotate k is %d\n", n, k);
    printf("Array before rotate\n");
    PRINT_ARRAY(arr, n);
    int ret = rotateArray(arr, n, k);
    if(ret == 0)
    {    
        printf("Rotated array with the %d times rotation\n", k);
        printf("Array After rotate\n");
        PRINT_ARRAY(arr, n);
    }
    else
    {
        printf("Array rotation not required\n");
    }

    return 0;
}