#include<stdio.h>
#include<stdlib.h>
void enque(int q[100],int *r);
void deque(int q[100],int *r,int *f);
void display(int q[100],int r,int f);
void main()
{
 int q[99],front=0,rear=-1,ch;
 while(1)
 {
  printf("n1.enque\nn2.deque\nn3.display\nn4.exit\n");
  printf("Enter the choice\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:enque(q,&rear);
          break;
   case 2:deque(q,&rear,&front);
         break;
   case 3:display(q,rear,front);
         break;
   case 4:exit(0);
  }
}
}
void enque(int q[100],int *r)
{
 int ele;
 if(*r==99)
 printf("Queue is full");
 else
 printf("Enter the element to be added");
 scanf("%d",&ele);
 *r=*r+1;
 q[*r]=ele;
}
void deque(int q[100],int *r,int *f)
{
 if(*f>*r)
 printf("Queue is empty");
 else
 printf("Deleted element =%d\n",q[*f]);
 *f=*f+1;
}
void display(int q[100],int r,int f)
{
 int i;
 if(f==r)
 printf("Queue is empty");
 else
 printf("Elements of queue\n");
 for(i=f;i<=r;i++)
 printf("%d \n",q[i]);
}
 