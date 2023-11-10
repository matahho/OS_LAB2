#include "types.h"
#include "stat.h"
#include "user.h"

#define STDOUT 1
 
int main(int argc, char *argv[]) 
{
  int parent_proc = getpid();
  int child_proc = fork();
  sleep(10);
  kill(child_proc);
  sleep(15);
  printf(STDOUT, "Parent Process Lifetime : %d Clock Ticks\n Child Process Lifetime : %d Clock Ticks\n", processLifetime(parent_proc), processLifetime(child_proc));
  exit();
} 