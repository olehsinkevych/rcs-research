#include <stdio.h>
#include <sys/vfs.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
	FILE * stat = fopen("stat.txt","w");
	struct statfs fs;
	printf("StatFs info\n\n");
	if(statfs("/home/fl3x/Documents/OSi/8/getinfo.c",&fs)==-1){
		printf("Error while reading\n");
		fprintf(stat,"Error while reading\n");
		exit(-1);
	}
	else{
		printf("Blocks amount %ld, available: %ld\n",fs.f_blocks,fs.f_bavail);
		fprintf(stat,"Blocks amount %ld, available: %ld\n",fs.f_blocks,fs.f_bavail);
	}
	printf("proc/ info\n\n");
	
	int handle;
	char minfo[1024+1],*match;
     ssize_t nread;
     handle = open("/proc/meminfo",O_RDONLY);
     if (handle<0){
		 printf("Failed to open /proc/meminfo\n");
		 fprintf(stat,"Failed to open /proc/meminfo\n");
	 }
	 nread=read(handle,minfo,sizeof(minfo)-1);
	 if (nread<0){
		 printf("Failed to read from /proc/meminfo");
		 fprintf(stat,"Failed to read from /proc/meminfo");
		 close(handle);
	 }
	 close(handle);
	 minfo[nread]='\0';
	 match = minfo;
	 while(*match){
		 char *eol = match + strcspn(match,"\n");
		 if (!*eol){
			 break;
		 } 
		 *eol++=0;
		 char *tag = match;
		 match = eol;
		 char *value = tag + strcspn(tag,":");
		 *value++ = 0;
		 if (strcmp(tag,"MemTotal")==0){
			printf("MemTotal: %s\n",value);
			fprintf(stat,"MemTotal: %s\n",value);
		}
		 if (strcmp(tag,"MemFree")==0){
		 printf("MemFree: %s\n",value);
		 fprintf(stat,"MemFree: %s\n",value);
	 }
		 if(strcmp(tag,"MemAvailable")==0){
			 printf("MemAvailable: %s\n",value);
			  fprintf(stat,"MemAvailable: %s\n",value);
		 }
		 if (strcmp(tag,"Buffers")==0){
			printf("Buffers: %s\n",value);
			fprintf(stat,"Buffers: %s\n",value);
		}
		 if(strcmp(tag,"Cached")==0){
			printf("Cached: %s\n",value);
			fprintf(stat,"Cached: %s\n",value);
		}
	 }
	 char  cpuinfo[1024];
	 handle = open("/proc/cpuinfo",O_RDONLY);
	                       if (handle<0){
		 printf("Failed to open /proc/cpuinfo\n");
		 fprintf(stat,"Failed to open /proc/cpuinfo\n");
	 }
	 nread=read(handle,cpuinfo,sizeof(cpuinfo)-1);
	 if (nread<0){
		 printf("Failed to read from /proc/cpuinfo");
		 fprintf(stat,"Failed to read from /proc/cpuinfo");
		 close(handle);
	 }           
	 close(handle);
	 cpuinfo[nread]='\0';
	 match = cpuinfo;
	 while(*match){
		 char *eol = match + strcspn(match,"\n");
		 if (!*eol){
			 break;
		 } 
		 *eol++=0;
		 char *tag = match;
		 match = eol;
		 char *value = tag + strcspn(tag,":");
		 *value++ = 0;
		 if(strcmp(tag,"model name	")==0){
		   printf("CPU: %s\n",value);
		   fprintf(stat,"CPU: %s\n",value);
	   }
		   if(strcmp(tag,"cpu MHz		")==0){
		    printf("cpu MHZ: %s\n",value);
		    fprintf(stat,"cpu MHZ: %s\n",value);
		}
		    if (strcmp(tag,"bogomips	")==0){
		   printf("CPU boost MHZ: %s\n",value);
		   fprintf(stat,"CPU boost MHZ: %s\n",value);
	   }
		   if (strcmp(tag,"cache size	")==0){
		   printf("CPU cache size: %s \n",value);
		   fprintf(stat,"CPU cache size: %s \n",value);
	   }
	 }  
	 fclose(stat);
}
