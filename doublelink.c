#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *rear;
};

typedef struct node* node;
node head = NULL;
node getnode()
{
	node temp;
	temp = (node)malloc(sizeof(node));
	temp->next = NULL;
	temp->rear = NULL;
	return temp;
}

node put_front(node head,int ele)
{
	node temp;
	temp = getnode();
	temp->data = ele;
	if(head==NULL)
	{
		head = temp;
	}
   else
	{
		temp->next=head;
		head->rear = temp;
		temp->rear = NULL;
		head = temp;
	}
	return head;
}

node put_end(node head,int ele)
{
	node temp1;
	node temp2;
	temp1=getnode();
	temp1->data = ele;
	if(head==NULL)
	{
		head = temp1;
	}
  else
	{
		temp2 = head;
		while(temp2->next!=NULL)
		{
			temp2 = temp2->next;
		}
		temp2->next = temp1;
		temp1->rear = temp2;
	}
	return head;
}

void display(node head) {
	node temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

node ins_pos(node head,int ele,int pos) {
	node temp;
	node curr=head;
	node prev=NULL;
	int count=1;
	temp = getnode();
	temp->data = ele;
	if(head==NULL) {
		printf("Empty\n");
	}
   else {
		while(count<pos && curr!=NULL)
		{
			prev = curr;
			curr=curr->next;
			count++;
		}
		if(curr==NULL && count<pos) {
			printf("Not possible\n");
		}
	else if(curr==NULL && count==pos) {
		prev->next=temp;
		temp->rear = prev;
		printf("%d was inserted successfully in %d positon\n",ele,pos);
	}
	else {
		temp->next = curr;
		temp->rear = (curr->rear);
		(curr->rear)->next = temp;
		curr->rear = temp;
		printf("%d was inserted successfully in %d positon\n",ele,pos);
	     }
	}
	return head;
}

node del_front(node head) {
	node temp=head;
	if(head==NULL) {
		printf("Empty\n");
	}
  else {
		printf("%d was deleted successfully\n",head->data);
		head = head->next;
		head->rear = NULL;
		free(temp);
	}
	return head;
}

node del_end(node head) {
	node temp=head;
	if(head==NULL) {
		printf("Empty\n");
	}
  else {
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		printf("%d was deleted successfully\n",temp->data);
		(temp->rear)->next = NULL;
		free(temp);
	}
	return head;
}

node del_ele(node head,int ele) {
	node temp=head;
	if(head==NULL) {
		printf("Empty\n");
	}
  else {
		while(temp->data!=ele && temp->next!=NULL)
		{
			temp=temp->next;
		}
		if(temp->data==ele && temp->next==NULL) {
			printf("%d was deleted successfully\n",temp->data);
			(temp->rear)->next=NULL;
			temp->rear = NULL;
			free(temp);
		}
	else if(temp->data!=ele && temp->next==NULL)
		{
 			printf("Invalid\n");
		}
	else if(temp->data==ele && temp->rear==NULL) {
		printf("%d was deleted successfully\n",temp->data);
		head=temp->next;
		(temp->next)->rear=NULL;
		free(temp);
	}
	else {
		 printf("%d was deleted successfully\n",temp->data);
		(temp->rear)->next = temp->next;
		(temp->next)->rear = temp->rear;
		free(temp);
	}
   }
	return head;
}
void main()
{
	int ch,ele,pos;
	do {
		printf(" Enter 1 to insert from front\n Enter 2 to insert from end\n Enter 3 to display\n Enter 4 to insert at the  pos\n Enter 5 to delete from front\n Enter 6 to delete from end\n Enter 7 to delete element\n ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the element to be inserted in front\n");
				scanf("%d",&ele);
				head = put_front(head,ele);
				printf("%d was inserted successfully\n",ele);
				break;
			case 2: printf("Enter the element to be inserted in end\n");
				scanf("%d",&ele);
				head = put_end(head,ele);
				printf("%d was inserted successfully\n",ele);
				break;
			case 3: display(head);
				break;
			case 4: printf("Enter element to be inserted\n");
				scanf("%d",&ele);
				printf("Enter position\n");
				scanf("%d",&pos);
				head = ins_pos(head,ele,pos);
				break;
			case 5: head = del_front(head);
				break;
			case 6: head = del_end(head);
				break;
			case 7: printf("Enter element\n");
				scanf("%d",&ele);
				head = del_ele(head,ele);
				break;
			case 8: exit(1);
		}
	}while(ch!=9);
}

