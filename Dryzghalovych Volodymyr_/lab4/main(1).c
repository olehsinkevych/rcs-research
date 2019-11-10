#include <stdio.h> 


void hell()
{
printf("Hello World!\n");
}

void calc(double a, double b)

{
printf("a+b=%le \n",a+b);
printf("a-b=%le \n",a-b);
printf("a*b=%le \n",a*b);
printf("a/b=%le \n",a/b);
}

int main()
{
double a,b;
hell();
printf("Input two numbers"); 
scanf("%le",&a);
scanf("%le",&b); 
calc(a,b);
return 0;
}
