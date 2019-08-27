#include <stdio.h>
#include<string.h>
int prec(char c)
{
    int  p ;
    if(c=='(')
    {
        p=0 ;
    }
    if(c=='^')
    {
        p=3 ;
    }
    if(c=='*'||c=='/')
    {
        p=2 ;
    }
    if(c=='+'||c=='-')
    {
        p=1 ;
    }
    return p ;
}
void push(char c,int *top,int*p)
{
    if(*top>=100)
    {
        printf("stack overflow\n") ;
        return ;
    }
    *(p+*top)=c ;
    (*top)+=1 ;
}
char pop(int *top,int*p)
{
    if(*top<0)
    {
        printf("stack underflow\n");
        top-- ;
        return ;
    }
    (*top)-- ;
    char a=*(p+*top) ;

    return a ;
}
int main ()
{
    char stack[100] ;
    int top=0 ;
    printf("enter the infix expression\n") ;
    char infix[100] ;
    gets(infix) ;
    int l=strlen(infix) ;
    for(int x=0;x<=l;x++)
    {
        if(x==l)
        {
            while(top>1)
            {
                char v=pop(&top,&stack[0]) ;
                printf("%c",v) ;

            }
        }
        if(infix[x]=='(')
        {
            push(infix[x],&top,&stack[0]) ;
        }
        else if(infix[x]=='+'||infix[x]=='-'||infix[x]=='^'||infix[x]=='*'||infix[x]=='/')
        {
            if(top==0)
            {
                push(infix[x],&top,&stack[0]) ;
            }
            int pi=prec(infix[x]) ;
            int pt=prec(stack[top-1]) ;
            while(pi<pt)
            {
                char j=pop(&top,&stack[0]) ;
                printf("%c",j) ;
                pt=prec(stack[top]) ;
            }
            push(infix[x],&top,&stack[0]) ;

        }
        else if(infix[x]==')')
        {
            char g=pop(&top,&stack[0]) ;
            while(g!='(')
            {
                printf("%c",g) ;
                g=pop(&top,&stack[0]) ;
            }
        }
        else
        {
            printf("%c",infix[x]) ;
        }

    }

}