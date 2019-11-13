#include <stdio.h> 
#include "secondary.c"

int main()
{
double a,b;
hello();
printf("Input two numbers"); 
scanf("%le",&a);
scanf("%le",&b); 
calc(a,b);
return 0;
}
