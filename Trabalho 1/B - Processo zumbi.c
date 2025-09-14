#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int exitSon=0;

void receivedSignal(int s){
  exitSon=s;
}

int main(){

  signal(SIGUSR1, receivedSignal);
  signal(SIGUSR2, receivedSignal);

  pause();
  
  if(fork()==0)
    exit(0);

  pause();
  wait(NULL);
  pause();
  exit(0);    
}