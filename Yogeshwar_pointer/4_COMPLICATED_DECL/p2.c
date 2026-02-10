#include <stdio.h> 
#include <stdlib.h> 

int (*pA)[5]; 
int a[5] = {10, 20, 30, 40, 50}; 

int main(){
	int i; 
	int m; 

	pA = &a; 

	for(i = 0; i < 5; ++i){
		m = (*pA)[i];
		printf("m = %d\n", m); 
	}

	return (0); 
}