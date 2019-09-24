#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE p;
    p=(NODE)malloc(sizeof(struct node));
    if(p!=NULL)
        return p;
    else
        {
            printf("Memeory couldnt be aloocated");
           exit(0);
        }
}
NODE insert_beg(NODE head,int ele)
{
    NODE p;
    p=getnode();
    p->data=ele;
    p->next=head;
    head=p;
    return head;
}
NODE insert_end(NODE head,int ele)
{
     NODE p,q;
     p=getnode();
     p->data=ele;
     q=head;
     if(head==NULL)
        return q;
     while(q->next!=NULL)
     {
         q=q->next;
     }
      q->next=p;
      p->next=NULL;
      return head;
}
NODE insert_pos(NODE head,int item,int pos)
{
	NODE curr,prev=NULL,newn;
	int count=1;
	newn=getnode();
	newn->data=item;
	newn->next=NULL;
	if(head==NULL)
	{
		if(pos==1)
			return newn;
		else
		{
			printf("Invalid position\n");
			return 0;
		}
	}
	if(pos==1)
	{
		newn->next=head;
		head=newn;
		return head;
	}
	else
	{
		curr=head;
		while(curr!=NULL&&count!=pos)
		{
			prev=curr;
			curr=curr->next;
			count++;
		}
		if(count==pos)
		{
			prev->next=newn;
			newn->next=curr;
			return head;
		}
		else
		{
			printf("Invalid position\n");
			return head;
		}
	}
}

 void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("List is empty\n");
		return ;
	}
	p=head;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}
NODE delete_front(NODE head)
{
  if(head==NULL)
  {
    printf("LIST IS EMPTY");
    return head;
    }
        head=head->next;
        return head;
      
 }
 NODE delete_end(NODE head)
 {
    NODE p=head;
     if(head->next==NULL)
     {
       return head;
       }
    while((p->next)->next!=NULL)
    {
      p=p->next;
     }
     printf("DELTED ELEMENT=%d",p->data);
      p->next=NULL;
      return head;
 }
int main()
{
    NODE head=NULL;
    int option,ele,n,pos,value,i=0;
	while(i!=5)
	{
		printf("1.Insert front\n2.Insert end\n3.Inset pos\n4.Display\n5.Delete front\n6.Delete end\n7.EXIT\n");
		printf("Enter option\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1: printf("Enter element to be inserted\n");
				scanf("%d",&ele);
				head=insert_beg(head,ele);
				break;
			case 2: printf("Enter element to be inserted\n");
				scanf("%d",&ele);
				head=insert_end(head,ele);
				break;
			case 3:printf("Enetr pos and value\n");
				scanf("%d%d",&pos,&value);
				head=insert_pos(head,value,pos);
				break;
			case 4:printf("Elements in list are\n");
				display(head);
				break;
			case 5:
			       head=delete_front(head);
				break;
                        case 6:
                                head=delete_end(head);
                                break;
                        case 7:
                               exit(0);

		}
	}

	return 0;
}
