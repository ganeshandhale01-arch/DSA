#include <stdio.h> 
#include <stdlib.h> 

/* 
P7: Declare an array 5 of pointers to function accepting two integers and 
	returning an integer 
	
	S1: Declare an array 5 of 
		arr[5]

	S2: Declare an array 5 of pointer to 
		*arr[5]
	
	S3: Declare an array 5 of pointer to function 
		(*arr[5])()

	S4: Declare an array 5 of pointer to function accepting 
		two integers and returning an integer
		
		int (*arr[5])(int, int); 
*/ 

int cpa_add(int, int); 
int cpa_sub(int, int); 
int cpa_mul(int, int); 
int cpa_div(int, int); 
int cpa_mod(int, int); 

int main(void)
{
	int (*arr[5])(int, int);	
	int a = 10, b = 3; 
	int i; 
	int ret; 

	arr[0] = cpa_add; 	// 13 
	arr[1] = cpa_sub; 	// 7 
	arr[2] = cpa_mul; 	// 30 
	arr[3] = cpa_div; 	// 3 
	arr[4] = cpa_mod; 	// 1 

	for(i = 0; i < 5; ++i)
	{
		ret = arr[i](a, b); 
		printf("ret = %d\n", ret); 
	}

	return (0); 	
}

int cpa_add(int a, int b)
{
	return (a+b); 
}

int cpa_sub(int a, int b)
{
	return (a-b); 
}

int cpa_mul(int a, int b)
{
	return (a*b); 
}

int cpa_div(int a, int b)
{
	return (a/b); 
}

int cpa_mod(int a, int b)
{
	return (a%b); 
}

void f(void){
	std::unique_ptr<int> p_int(new int(100)); 
}