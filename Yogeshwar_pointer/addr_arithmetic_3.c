#include <stdio.h> 

struct A{
    int x; 
    int y; 
    int z; 
}; 

struct B{
    double x; 
    int y; 
    double z; 
}; 

int main(void){
    struct A inA; 
    struct B inB; 

    printf("Base address of inA = %llu\n", &inA); 
    printf("Addr of member y in inA:%llu\n", &inA.y); 
    puts("--------------------"); 
    printf("Base address of inB = %llu\n", &inB); 
    printf("Addr of member y in inB = %llu\n", &inB.y); 
    puts("--------------------"); 
    
    return (0); 
}