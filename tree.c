#include<stdio.h>
#include<stdlib.h>
struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};
typedef struct tree *Node;

Node getnode()
{
	Node x;
	x=(Node)malloc(sizeof(Node));
    x->left=NULL;
	x->right=NULL;
	return x;
}

Node insert(Node curr,int item)
{
	if(curr==NULL)
	{
	    curr=getnode();
	    curr->data=item;
	}
	else
	{
	    if(item<curr->data)
	        curr->left=insert(curr->left,item);
	    else
	        curr->right=insert(curr->right,item);
	}
	return curr;
}

void inorder(Node root)
{
	Node r;
	r=root;
	if(r != NULL)
	{
		inorder(r->left);
		printf("%d->",r->data);
		inorder(r->right);
	}
}

void preorder(Node root)
{
	Node r;
	r=root;
	if(r !=NULL )
	{
		printf("%d->",r->data);
		preorder(r->left);
		preorder(r->right);
	}
}
void postorder(Node root)
{
	Node r;
	r=root;
	if(r !=NULL )
	{
		postorder(r->left);
		postorder(r->right);
		printf("%d->",r->data);
	}
}
void main()
{
	Node root = NULL;
	int i,item,n;
	while(1)
	{
		printf("\n1.Enter 1 tocreating a binary search tree\n");
		printf("2.Enter 2 to display in preoder\n");
		printf("3.Enter 3 to display in inorder\n");
		printf("4.Enter 4 to display in postorder\n");
		printf("5.Enter 5 to exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
			printf("enter 0 end\n");
			printf("enter data: ");
			scanf("%d",&item);
			while(item!=0)
			{
				root=insert(root,item);
				printf("enter data: ");
				scanf("%d",&item);
			}
			break;
			case 2:
			printf("Showing traversal in PREORDER:\n");
			preorder(root);
			break;
			case 3:
			printf("Showing  traversal in INORDER:\n");
			inorder(root);
			break;
			case 4:
			printf("Showing traversal in POSTORDER:\n");
			postorder(root);
			break;
			case 5:
			exit(0);
		}
	}
}