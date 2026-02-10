#include <stdio.h> 

void test(void); 

int main(void){
    int a[5] = {100, 200, 300, 400, 500}; /* a is array five of integers */
    int (*pa)[5];   /* pa is pointer to array 5 of integers */
    pa = &a;        /* store the base address of array of 5 integers 
                    into pointer to array 5 of integers */
    int i; 
    int current_element; 

    puts("Using ABNORMAL method"); 
    for(i = 0; i < 5; ++i){
        current_element = (*pa)[i];
        printf("Element at index %d is %d\n", i, current_element);  
    }

    puts("Using normal method"); 
    test(); 

    return (0); 
}

void test(void){
    int a[5] = {100, 200, 300, 400, 500}; 
    int* p = a; 
    int i; 
    int current_element; 
    for(i = 0; i < 5; ++i){
        current_element = p[i]; 
        printf("element at index %d is %d\n", i, p[i]); 
    }
}

/* 
    Technicality: 
    Data Definition Statement: 
    Category 1: 
    All type information is on LHS of variable. 

    int n; 
    char c; 
    struct Date myDate; 

    Category 2: 
    Type information of variable is split on LHS as well as on RHS 
    int a[5]; 

    Part of type information which tells that a is array of 5 elements 
    is '[5]'. This part of type information lies on the right of variable name. 

    Part of type information which tells that each element in array is integer 
    is 'int'. This part of type information lies on the left of variable name. 
    int     [5] 

    While declaring a pointer to variables, the type information of pointer 
    mimics the pattern of type information of category of variable. 
    ---------------------------------------------------------------------------
    Part of type information which makes a particular variable of pointer type 
    lies on the left of variable. 

    int *p; 

    #---------------------------------------------------------------------

    int a[5]; 
    int     [5];    [5]->right  int->left

    *p

    int (*p)[5];

    int fun(int a, int b){

    } 

    int     (int, int)
    int    (*p)  (int, int)
    int (*pfn)(int, int);  

    std::function<int(int, int)> fun = [](int a, int b)->int{

    }; 
*/