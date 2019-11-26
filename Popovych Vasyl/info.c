#include <stdio.h>

#include <string.h>



int main()

{

FILE* cpu;

FILE* mem;



char infoproc[1000];

size_t bytes_read;

char* match;

float speed;



cpu=fopen("/proc/cpuinfo","r");

bytes_read=fread(infoproc,1,sizeof(infoproc),cpu);



fclose(cpu);

infoproc[bytes_read]=='\0';

printf("\nInformation about CPU\n\n%s\n\n",infoproc);



char infomemory[500];

mem=fopen("/proc/meminfo","r");

bytes_read=fread(infomemory,1,sizeof(infomemory),mem);

fclose(mem);
 
infomemory[bytes_read]=='\0';

printf("\nInformation about memory\n\n%s\n\n",infomemory);

return 0;

}
