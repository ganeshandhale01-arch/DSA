#include<stdio.h>
#include<stdint.h>
#include<limits.h>


int main()
{
    int arr[] = {1, 2, 6, 3, 4, 5, 5, 6, 7, 8, 8, 9, 9};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    int ret = -1;

    printf("Original Array size = %d \n: ", size);
    for (size_t i = 0; i < size; i++)    
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    size_t j = 0;
    for (size_t i = 1; i < size; i++)
    {
        if (arr[j] != arr[i])
        {
            //j++;
            arr[++j] = arr[i];
        }
    }

    printf("Array after removing duplicates size %d\n: ", j + 1);
    for (size_t i = 0; i < j + 1; i++)    
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}