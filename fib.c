#include<stdio.h>
int fibo(int n);
int main()
{
	int i,n,f;
	printf("enter the value of n");
	scanf("%d",&n);
	
	
      for(i=0;i<n;i++){
f=fibo(i);
	printf("%d",f);}
}
int fibo(int n)
{
	if(n==0)
	return 0;
	else if(n==1)
	return 1;
	else
	return (fibo(n-1)+fibo(n-2));
}
				
