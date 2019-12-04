#include  <stdio.h> 
#include  <stdlib.h> 
#include  <pthread.h>

void  *secondTh(void  *value)
{
int  i=0; 
for(i=100;i<110;i++)
	{
	printf("Value  of  the  second  thread:  %d\n",i); sleep(2);
	}
}


int  main(int  argc,  char  const  *argv[])
{
pthread_t  mainTh; 
pthread_create(&mainTh,NULL,secondTh,NULL); 
int  i=0;
for(i=0;i<5;i++)
{
printf("Value  of  the  main  thread:  %d\n",i); 
sleep(1);
}
pthread_join(mainTh,NULL); 
return  0;
}
