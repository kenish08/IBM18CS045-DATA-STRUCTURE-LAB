#include<stdio.h>
int mulnumber(int n);
int main()
{
		int n,f;
		printf("enter the positive number");
		scanf("%d",&n);
		f=mulnumber(n);
		printf("factorial of %d is %d",n,f);
		return(0);
	}
int mulnumber(int n)
{
	if(n>=1)
	return n*mulnumber(n-1);
	else
	return 1;
}	
