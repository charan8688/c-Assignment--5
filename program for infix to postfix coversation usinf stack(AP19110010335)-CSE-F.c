#include<stdio.h>
char stack[20];
int high = -1;
void push(char x)
{
    stack[++high] = x;
}
 
char pop()
{
    if(high == -1)
        return -1;
    else
        return stack[high--];
}
 
int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}
 
main()
{
    char exp[20];
    char *a, x;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    a = exp;
    while(*a != '\0')
    {
        if(isalnum(*a))
            printf("%c",*a);
        else if(*a == '(')
            push(*a);
        else if(*a == ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while(priority(stack[high]) >= priority(*a))
                printf("%c",pop());
            push(*a);
        }
        a++;
    }
    while(high != -1)
    {
        printf("%c",pop());
    }
}