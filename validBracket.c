#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
void push(char *stk,int *top,char item)
{
    *top=*top+1;
    stk[*top]=item;
}
void pop(char *stk,int *top)
{
    if(*top>=0)
    {
        *top=*top-1;
    }
    else
    {
        push(stk,top,')');
    }
}
int main()
{
    int top=-1,len,i=0;
    char *str,*stk;
    stk=(char*)malloc(sizeof(char)*MAX);
    str=(char*)malloc(sizeof(char)*100);
    printf("Enter the expression:\n");
    fgets(str, 100, stdin);
    while(i<len)
    {
        char curr=str[i];
        if(curr=='(')
        {
            push(stk,&top,curr);
        }
        else if(curr==')')
        {
            pop(stk,&top);
        }
        i++;
    }
    if(top==-1)
    {
        printf("Parenthesis are balanced.\n");
    }
    else{
        printf("Parenthesis are not balanced.\n");
    }
}