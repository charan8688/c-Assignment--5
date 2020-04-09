#include<stdio.h>
#include<string.h>
#define MAXIMUM 20

int high = -1;
char stack[MAXIMUM];
char push(char i)
{
	if(high == (MAXIMUM-1))
		printf("Stack Overflow");
	else
		stack[++high] =i;
}
char pop()
{
	if(high == -1)
		printf("Stack underflow");
	else
		return stack[high--];
}
main()
{
	char str[20];
	int n;
	printf("Enter the string = " );
	gets(str);
	for(n=0;n<strlen(str);n++)
		push(str[n]);
	for(n=0;n<strlen(str);n++)
		str[n]=pop();
	printf("reverse string ");
	puts(str);
}