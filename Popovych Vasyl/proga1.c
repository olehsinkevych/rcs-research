#include <stdio.h> 
#include <string.h> 

int main()
{
char myString[128];
int i;
printf( "Function #1 - fgets() \n" ); 
printf( "Input string: " ); 
fgets( myString, 128, stdin ); 
	for ( i = 0; i < 128; i++ ){
		if ( myString[i] == '\n' ){	
		myString[i] = '\0'; break;
	}
	}
char Str[128] = "";
char addStr[128] = "";
printf( "You have entered: %s \n\n", myString );
printf( "Function #2 - strlen() \n" ); 
printf("Input some text:\n"); scanf("%s",Str);
printf ("String %s",Str);
printf(" consists of %lu", strlen(Str)); 
printf(" symbols!\n\n");
printf( "Function #3 - strcat \n" ); 
printf("String #1 - %s \n", myString); 
printf("String #2 - %s \n",Str);
strcat(addStr , myString); 
strcat(addStr , Str);
printf("String #3 after concetenation - %s \n\n", addStr);
printf( "Function #4 - strcpy \n" ); printf("String #1 - %s \n", myString); 
printf("String #2 - %s \n",Str); 
strcpy(myString, Str);
printf("String #1 after copying - %s \n\n", myString);
printf( "Function #5 - strcmp \n" ); 
printf("String #1 - %s \n", myString); 
printf("String #2 - %s \n",Str);
printf("Result of comparing: %i \n", strcmp(myString, Str)); 
printf("String #1 - %s \n", myString);
printf("String #3 - %s \n",addStr);
printf("Result of comparing: %i \n", strcmp(myString, addStr));
return 0;
}
