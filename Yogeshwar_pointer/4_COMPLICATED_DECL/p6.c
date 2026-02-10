#include <stdio.h> 
#include <stdlib.h> 

/* 
Declare a pointer to function accepting 
		(1)an int
		(2) a pointer to function accepting int and returning void  
		returning 
		a pointer to function accepting int and returning void
*/ 

/* Solution: 
	
	S11: Pointer to a function 
		(*)() 

	S12: Pointer to function accepting int 
		(*)(int)

	S13: Pointer to function accepting int and returning void 
		void (*)(int)
	#-----------------------------------------------------------
	S21:	my_function is a function 
			my_function()

	S22: 	my_function is a function accepting 
			(a) integer 
			(b) pointer to a function accepting int and returning void 
				(Refer S11-S13)

			my_function(int, void (*)(int)) 

	S23: 	my_function is a function accepting 
			(a) integer 
			(b) a pointer to a function accepting int and returning void 

			Returning 
			pointer 

			*my_function(int, void(*)(int))

	S24: 	my_function is a function accepting 
			(a) integer 
			(b) a pointer to a function accepting int and returning void 

			returning 
			a pointer to a function 

			(	*my_function(int, void(*)(int))	) ()

	S25: 	my_function is a function accepting 
			(a) integer 
			(b) a pointer to a function accepting int and returning void 

			returning 
			a pointer to a function accepting int and returning void 
				
			void (*my_function(int, void (*)(int)))(int); 
	#-------------------------------------------------------------------------
	
	S31: 	pointer to a function 

			(*)()

	S32: 	A Pointer to a function accepting 
			(a) integer 
			(b) a pointer to a function accepting int and returning void 

			returning 
			a pointer to a function accepting int and returning void 
			(Refer S25)

			void (*(*pfn)(int, void(*)(int)))(int); 

			pfn is a pointer to a function accepting 
			(a) integer 
			(b) a pointer to a function accepting int and returning void 
			and returning 
			a pointer to a function accepting int and returning void 
*/ 	

void first_handler(int); 
void second_handler(int); 
void (*exchange(int, void(*)(int)))(int); 

int main(void){
	void (*pfn)(int); 

	pfn = exchange(10, first_handler); 
	if(pfn == NULL)
		puts("main:no previously registered handler"); 

	pfn = exchange(20, second_handler); 
	if(pfn != NULL){
		pfn(100); 	/* first_handler */ 
	}

	pfn = exchange(30, NULL);
	if(pfn != NULL){
		pfn(200); 	/* second_handler */ 
	} 

	return (0); 
}

void first_handler(int n){
	printf("first_handler:n = %d\n", n); 
}

void second_handler(int m){
	printf("second handler:m = %d\n", m); 
}

void (*exchange(int k, void(*pfn_new)(int)))(int){
	static void (*pfn_saved)(int) = NULL; 
	void (*return_pfn)(int); 

	return_pfn = pfn_saved; 
	pfn_saved = pfn_new; 

	return (return_pfn); 
}

