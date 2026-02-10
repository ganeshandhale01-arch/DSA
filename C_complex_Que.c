/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    
    int f;
    static int p;
    int n = 8;
    if(p == 0)
        printf("Hello World = %d\n", (! (n) & (n-1)));
    else if(p==48)
        printf("hgdfshf");
    else
        printf("fshgg" );
    
    char str[5] = "C Programming";
    printf("%s\n", str);
    

    int sum;
    printf("%d\n", sum^sum);
    
    
    enum stat
    {
        a,
        b,
        c
    };
    
    enum stat std1, std2, std3;
    std1= a;
    std2= c;
    std3= b;
    printf("\n %d, %d, %d", std1, std2, std3);
    return 0;
}