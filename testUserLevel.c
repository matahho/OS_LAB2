#include "types.h" // for basic types like int , char , ...
#include "stat.h"  // fro file status constatnts . 
#include "user.h" // for user-level program systemcalls and definitiosn 



int main (){
	int thePID = getpid(); // getpid system call

	//printf(1 ,"The prossec ID is : %d\n" , thePID); // this write the pid in stdout (1<-fd)
	exit();


}