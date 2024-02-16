#include "types.h"
#include "user.h"
#include "stat.h"


int main (int argc , char* argv[] ){
	if (argc < 2 ){
		printf(2 , "Error : You should get a number as input argument\n");
		exit();

	}

	if (argv[1][0] == '-'){
		printf(2 , "Error : You should get a POSITIVE number as input argument\n");
		exit();
	}

	
	// I will use ebx register for the value .

	int saved_ebx;
	int input = atoi(argv[1]);
	asm volatile(

			"movl %%ebx ,%0;" //saved_ebx=ebx .
			"movl %1 , %%ebx;" // ebx=input . 
			: "=r" (saved_ebx)
			: "r" (input)

		);
	printf(1 , "Find_digital_root called by user\n");
	printf(1 , "The ditital_root for %d is equal to : %d\n", input , find_digital_root());


	asm (
		"movl %0 , %%ebx" : : "r"(saved_ebx)
		); // restore the ebx reg --> ebx = saved_ebx ;

	exit();




}