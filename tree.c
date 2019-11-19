#include <stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
	};
typedef struct node *NODE;
NODE getnode(int item)
{
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	p->data=item;
	p->lchild=NULL;
	p->rchild=NULL;
	return p;
}
void inorder(NODE root)
{
	if(root==NULL)
	return;
	inorder(root->lchild);
	printf("%d",root->data);
	inorder(root->rchild);	
}
void preorder(NODE root)
{
	if(root==NULL)
	return;
	printf("%d",root->data);
	preorder(root->lchild);
	preorder(root->rchild);	
}
void postorder(NODE root)
{
	if(root==NULL)
	return;
	postorder(root->lchild);
	postorder(root->rchild);	
	printf("%d",root->data);
}

NODE insert(NODE root,int item)
{
	if(root==NULL)
	return getnode(item);
	if(item<root->data)
	root->lchild=insert(root->lchild,item);
	else if(item>=root->data)
	root->rchild=insert(root->rchild,item);
	return root;
}
int main()
{
	int ch,n;
	NODE root=NULL;
	
	while(1)
	{
	printf("\nenter 1.inoder,2.preorder,3.postorder,4.insert");
	scanf("%d",&ch);
		switch(ch)
		{
			case 1:	inorder(root);
					break;
			case 2:preorder(root);
					break;
			case 3:postorder(root);
					break;
			case 4: printf("enter the element to insert:\n");
					scanf("%d",&n);
					root=insert(root,n);
					break;
			default:exit(0);
					break;	
			}
		}
}

					
	
	
	
	
	
	
	
	
	
	
	
	
