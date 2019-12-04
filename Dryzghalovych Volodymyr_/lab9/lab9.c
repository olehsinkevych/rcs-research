#include <dlfcn.h>
#include <stdio.h>
#include <string.h>

double(*void_func)();
void *lib;

void load_lib(char* pathname){

		lib =dlopen(pathname,RTLD_NOW);
		if (lib==NULL) printf ("\n !Error while opening lib!\n");
		else printf("\n Lib has been opened!\n");

}

void call_lib(char* func){
	if (lib ==NULL) printf ("\n Load lib first\n");
	else {
		void_func = dlsym(lib,func);
		char* err = dlerror();
		if (err!=NULL){ 
			printf("\n Smth wrong!\n");
			fprintf(stderr,"%s\n",err);
		}
		else (*void_func)();
	}
}

void unload (char* pathname){
	if (lib == NULL){
		printf("\n Nothing to close!\n");
	}
	else {
		dlclose(lib);
		printf("%s has been unloaded",pathname);
	}
}

int main(int argc, char const *argv[])
{
	char comm[50];
	char path[50];
	printf("\n\nMain program!!!\n\n Enter (load,unload,call,exit)");
	 while(1==1){
	 	printf("\n");
	 	scanf("%s",comm);
	 	if (strcmp(comm,"load")==0) {
	 		printf (" Enter path:\n");
	 		scanf("%s",path);
	 		load_lib(path);
	 	}
	 	else if (strcmp(comm,"unload")==0){
	 		printf (" Enter path:\n");
	 		scanf("%s",path);
	 		unload(path);
	 	}
	 	else if (strcmp(comm,"call")==0){
	 		printf (" Enter func name:\n");
	 		scanf("%s",path);
	 		call_lib(path);
	 	}
	 	else if (strcmp(comm,"exit")==0){
	 		return 0;
	 	}
	 	else printf("\n Incorrect input!\n");
	 }
	 return 0;
}
