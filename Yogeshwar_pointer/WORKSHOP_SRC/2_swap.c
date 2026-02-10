#include <stdio.h> 

void swap_1(int x, int y); 
void swap_2(int* px, int* py); 

void test_swap_1(void); 
void test_swap_2(void); 

int main(void){
    test_swap_1(); 
    test_swap_2(); 
    return (0); 
}

void swap_1(int x, int y){
    int tmp; 

    tmp = x; 
    x = y; 
    y = tmp; 
}

void swap_2(int* px, int* py){
    int tmp; 

    tmp = *px; 
    *px = *py; 
    *py = tmp; 
} 

void test_swap_1(void){
    int x = 100, y = 200; 

    puts("Testing swap_1:");
    printf("Before swap_1:x = %d, y = %d\n", x, y); 
    swap_1(x, y); 
    printf("After swap_1:x = %d, y = %d\n", x, y); 
    puts("-------------------------------------------"); 
}

void test_swap_2(void){
    int x = 100, y = 200; 

    puts("Testing swap_2:");
    printf("Before swap_2:x = %d, y = %d\n", x, y); 
    swap_2(&x, &y); 
    printf("After swap_2:x = %d, y = %d\n", x, y); 
    puts("-------------------------------------------"); 
}