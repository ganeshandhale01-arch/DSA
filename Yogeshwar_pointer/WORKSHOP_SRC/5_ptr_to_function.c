#include <stdio.h> 
#include <stdlib.h> 

int cpa_add(int, int); 
int cpa_sub(int, int); 
int cpa_mul(int, int); 
int cpa_div(int, int);

int main(void){
    int (*pfn)(int, int); 
    int choice; 
    int result; 
    int num1 = 14, num2 = 3; 
    
    puts("1:add, 2:sub, 3:mul, 4:div"); 
    printf("Enter your choice:"); 
    scanf("%d", &choice); 

    switch(choice){
        case 1: 
            pfn = cpa_add; 
            break; 
        case 2: 
            pfn = cpa_sub; 
            break; 
        case 3: 
            pfn = cpa_mul; 
            break; 
        case 4: 
            pfn = cpa_div; 
            break; 
        default: 
            puts("Invalid choice"); 
            exit(EXIT_FAILURE); 
    }    

    result = pfn(num1, num2); 
    printf("Result=%d\n", result); 

    return (0); 
}

int cpa_add(int a, int b){
    return (a+b); 
}

int cpa_sub(int a, int b){
    return (a-b); 
}

int cpa_mul(int a, int b){
    return (a*b); 
} 

int cpa_div(int a, int b){
    return (a/b); 
}