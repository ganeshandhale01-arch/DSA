#include <stdio.h> 

int main(void){
    int* p1[5]; 
    int (*p2)[5]; 

    printf("sizeof(p1):%llu\n", sizeof(p1)); 
    printf("sizeof(p2):%llu\n", sizeof(p2)); 

    return (0); 
}

