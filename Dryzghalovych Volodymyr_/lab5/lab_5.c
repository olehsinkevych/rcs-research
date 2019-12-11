#include <stdio.h> 
#include <signal.h> 
#include <unistd.h>

int main()
{
int pid = fork(); if(pid == 0) {
/* child */ 
while(1) pause();
} else {
/* parent */ 
sleep(1);
kill(pid, SIGKILL);
printf("pid %d should be a zombie\n", pid);
 while(1) pause();
}
}
