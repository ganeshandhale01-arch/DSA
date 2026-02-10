#include <stdio.h> 
#include <stdlib.h> 

int my_add(int n1, int n2); 

int main(){
	int (*pfn)(int, int) = NULL; 
	int ret; 

	pfn = my_add;
	ret = pfn(100, 200); 
	printf("ret = %d\n", ret); 

	return (0); 
}


int my_add(int n1, int n2){
	int sum; 
	sum = n1 + n2; 
	return (sum); 
}


/* 
	typeof(my_add): 
	
	int		(int, int)

	int (*p)(int, int); 
	p is pointer:
	*p 
	
	p is a pointer to function: 	
	(*p)()

	p is a pointer to function accepting two integers 
	(*p)(int, int)

	p is a pointer to a function accepting two integers and returning an integer 
	int (*p)(int, int)
*/ 

/* 
.section .text 

.globl my_add 
.type my_add, @function 
my_add: 
	pushl	%ebp 
	movl	%esp, %ebp 

	movl	8(%ebp), %eax
	addl 	12(%ebp), %eax

	movl	%ebp, %esp 
	popl	%ebp
	ret 
*/ 









