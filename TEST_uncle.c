#include "types.h"
#include "stat.h"
#include "user.h"


const int NUMBER_OF_CHILD = 10;

int
main(int argc, char *argv[])
{
  int i;
  int child_pid;
  int grandchild_pid;

  
  for (i = 0; i < NUMBER_OF_CHILD; i++) {
    child_pid = fork();
    if (child_pid < 0) {
      printf(1, "Fork failed\n");
      exit();
    } else if (child_pid == 0) {
      
       printf(1, "child pid: %d \n", getpid());
       if(i==1){
        exit();
       }
      // Child process
      if (i == (NUMBER_OF_CHILD-1)) {
        // Create a child for  last child
        grandchild_pid = fork();
        if (grandchild_pid < 0) {
          printf(1, "Fork failed\n");
          exit();
        } else if (grandchild_pid == 0) {

          int uncle_count = get_uncle_count();
          printf(1, "Grandchild pid: %d | Number of uncles: %d\n", getpid(), uncle_count);

          exit();
        }
      }
      break;
    }
  }

  if (child_pid > 0) {
    // Parent 
    sleep(30);  // Sleep to allow child processes to be created

    // Wait for all child processes to exit
    for (i = 0; i < (NUMBER_OF_CHILD+1); i++) {
      wait();
    }
  }

  exit();
}