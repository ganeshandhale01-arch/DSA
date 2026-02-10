#include <stdio.h>
#include <stdlib.h> 
/* 
	Declare a pointer to function accepting two integers and returns 
	a pointer to array 5 of int 

	
	my_function is a function 
	my_function()

	my_function is a function accepting two integers 
	my_function(int, int)
	
	my_function is a function accepts two integer and returns a pointer 
		*my_function(int, int)	 	
	
	my_function is a function which accepts two integer and return a pointer to array 
		(*my_function(int, int)) [5]
	
	my_function is a function which accepts two integer and returns a pointer to array 
	of integers 
	int (*my_function(int, int))[5]; 

	#--------------------------------------------------

	1] 	pfn is a pointer 
		*pfn
	
	2] 	pfn is a pointer to a function 
		(*pfn)()
		
	3] 	pfn is a pointer to a function which accepts two integers 
		(*pfn)(int, int)

	4] 	pfn is a pointer to a function which accepts two integers 
		and return a pointer 
		*(*pfn)(int, int)
	
	5] 	pfn is a pointer to a function which accepts two integers 
		and returns a pointer to array 5
		(*(*pfn)(int, int))[5]

	6] 	pfn is a pointer to a function which accepts two integers 
		and returns a pointer to array 5 of int 
		int (*(*pfn)(int, int))[5]; 

*/ printf(); 
 

/* Function declaration */ 
int (*my_function(int, int))[5]; 

/* pointer to function */ 
int (*(*pfn)(int, int))[5];

int main(void){
	pfn = my_function; 
	int (*pA)[5]; 
	int i; 
	int m; 

	pA = pfn(12, 4); 
	for(i = 0; i < 5; ++i)
	{
		m = (*pA)[i]; 
		printf("m = %d\n", m); 
	}

	return (0); 
}

int (*my_function(int a, int b))[5]
{
	static int A[5]; 

	A[0] = a + b; 
	A[1] = a - b; 
	A[2] = a * b; 
	A[3] = a / b; 
	A[4] = a * a; 

	return (&A); 	
}


/* 
int* get(void){
	int n; 

	return (&n); 
}

int* get(void){
	int* p; 

	p = malloc(sizeof(int)); 
	assert(p != NULL); 

	return (p); 
}

void get(int** pp){
	*pp = malloc(sizeof(int)); 
}

caller(){
	int* p = NULL; 

	get(&p); 
	*p = 100; 
	free(p); 
}

*/