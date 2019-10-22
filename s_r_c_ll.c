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
void sort(NODE head)
{
	NODE p=head,q=NULL;
	int temp;
	if(head==NULL)
	return;
	while(p->next!=NULL)
	{
	q=p->next;
	while(q!=NULL)
	{
	if(p->data>q->data)
	{
	temp=p->data;
	p->data=q->data;
	q->data=temp;
	}
	q=q->next;
	}
	p=p->next;
	}	
}
NODE reverse(NODE head)
{
	NODE curr=head,prev=NULL,nextn;
	
	while(curr!=NULL)
	{ne22
xtn=curr->next;
	curr->next=prev;
	prev=curr;
	curr=nextn;
	}
	head=prev;
	return head;
}
NODE concat(NODE head,NODE head2)
{
	if(head2==NULL)
	{return head;}
	if(head==NULL)
	{return head2;}
	while(head->next!=NULL)
	{
	head=head->next;
	}
	head->next=head2;
	return head;
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
int main()
{
    NODE head=NULL,head2=NULL;
    int ch,ele;
	while(ch!=0)
	{
		printf("\nenter 1.insert\n2.sort\n3.reverse\n4.concat\n5.display");
		scanf("\n%d",&ch);
	switch(ch)
	{
		case 1:printf("enter the ele to be instered");
			scanf("\n%d",&ele);
			head=insert_beg(head,ele);
			break;
		case 2:sort(head);
			break;
		case 3:head=reverse(head);
			break;
		case 4:printf("enter the second linked list");
			head=insert_beg(head2,ele);
			head=concat(head,head2);
			break;
		case 5:display(head);
			break;
		default: exit(0);
		}
	}
}	
		





























