#include "types.h" // for basic types like int , char , ...
#include "stat.h"  // fro file status constatnts . 
#include "user.h" // for user-level program systemcalls and definitiosn 


int main(int argc , char* argv[]){
	if (argc < 3){
		printf(1 ,"cp : need destination and source\n" );
		exit();
	}
	char *source = argv[1];
	char *dest = argv[2];

	if (copy_file(source , dest) < 0){
		printf(1 , "cp : cannot copy the file .\n");
		exit();
	}

	printf(1 , "Done\n");
	exit();

}
