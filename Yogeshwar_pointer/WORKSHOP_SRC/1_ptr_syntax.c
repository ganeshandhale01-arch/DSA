#include <stdio.h> 

int main(void){
    int n = 100; 
    int* p = &n; 

    /* 
        type(n) -> int 
        type(&n) -> int* 
        type(p) -> int*
        type(*p) -> int 
        int *p; 
    */

    printf("Before:*p = 200:n = %d\n", n); 
    *p = 200; 
    printf("After:*p = 200:n = %d\n", n); 
    return (0); 
}