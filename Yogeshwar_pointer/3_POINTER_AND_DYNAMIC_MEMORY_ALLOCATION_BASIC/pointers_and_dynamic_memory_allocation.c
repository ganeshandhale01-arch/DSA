#include <stdio.h> 
#include <stdlib.h> 

struct A
{
    int a; 
    char b; 
    int c; 
};

void builtin_demo(); 
void array_demo(); 
void structure_demo(); 

void error(); 

int main()
{
    builtin_demo(); 
    array_demo(); 
    structure_demo(); 
    return (0); 
}

void builtin_demo()
{
    char* cp = NULL; 
    int* pi = NULL; 
    float* fp = NULL; 
    
    puts("BUILT IN DEMO:"); 
    /* allocate */ 
    cp = (char*)malloc(sizeof(char)); 
    if(cp == NULL)
        error(); 
    /* write */ 
    *cp = 'K'; 
    /* read */ 
    printf("*cp = %c\n", *cp); 
    /* free */ 
    free(cp); 
    cp = NULL; 

    /* allocate */ 
    pi = (int*)malloc(sizeof(int)); 
    if(pi == NULL)
        error();
    /* write */
    *pi = 500; 
    /* read */ 
    printf("*pi = %d\n", *pi); 
    /* free */ 
    free(pi); 
    pi = NULL; 

    /* allocate */ 
    fp = (float*)malloc(sizeof(float)); 
    /* write */ 
    *fp = 500.500f; 
    /* read */ 
    printf("*fp = %f\n", *fp); 
    /* free */ 
    free(fp); 
    fp = NULL; 
}

void array_demo()
{   
    int* pa = NULL; 
    int i; 

    puts("ARRAY DEMO:"); 
    /* allocate array of 5 integers */ 
    pa = (int*)malloc(5*sizeof(int)); 
    if(pa == NULL)
        error(); 
    
    /* write */ 
    for(i = 0; i < 5; ++i)
        pa[i] = (i+1) * 10; 

    /* read */ 
    for(i = 0; i < 5; ++i)
        printf("pa[%d]:%d\n", i, pa[i]); 

    /* free */ 
    free(pa); 
    pa = NULL; 
}

void structure_demo()
{
    struct A* pA = NULL; 

    puts("STRUCTURE DEMO:"); 
    /* allocate */ 
    pA = (struct A*)malloc(sizeof(struct A)); 
    if(pA== NULL)
        error(); 
    /* write */ 
    pA->a = 1000; 
    pA->b = 'M'; 
    pA->c = 2000;

    /* read */ 
    printf("pA->a=%d, pA->b=%c, pA->c=%d\n", pA->a, pA->b, pA->c); 

    /* free */ 
    free(pA); 
    pA = NULL;  
}

void error()
{
    printf("error in allocating memory...exiting\n"); 
    exit(-1); 
}

/* 
    int a[5]; 
    a is array 5 of ints

    int* p; 

    int (*pa)[5];



*/