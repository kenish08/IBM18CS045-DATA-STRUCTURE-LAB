#include<stdio.h>
void tower1(int,char,char,char);
int main()
{
	int n;
	printf("enter the value of n");
	scanf("%d",&n);
	tower1(n,'A','B','C');
}
void tower1(int n, char src, char temp, char dest)
{
	if(n==1)
	{
		printf("move %d disc from %c to %c\n",n,src,dest);
		return;
	}
	tower1(n-1,src,dest,temp);
	printf("move %d disc from %c to %c\n",n,src,dest);
	tower1(n-1,temp,src,dest);
}

