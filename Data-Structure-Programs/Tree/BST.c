/*
Name			: Hungund Bilal
Roll No.		: IT-68
Program Name	: ID - BST
Write a menu driven program to implement binary search tree and perform the following operations:
1. Insert Node		7. Successor
2. Inorder			8. Predescessor
3. Preorder			9. Search
4. Postorder		10.Count Node
5. Tree Min			11.Internal Node
6. Tree Max			12.External Node
13.Height of Tree	14.Delete a Node
15.Delete Tree
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left;
	int data;
	struct node *right;
};
struct node *root = NULL;

struct node* getNode()
{
	return ((struct node *)malloc(sizeof(struct node)));
}
struct node* insertNode(struct node *root,int x)
{
	struct node *newNode;
	newNode = getNode();
	newNode->data = x;
	newNode->left = NULL;
	newNode->right = NULL;
	if(root == NULL)
	{
		root = newNode;
		return root;
	}
	else if(newNode->data < root->data)
	{
		root->left = insertNode(root->left,x);
	}
	else
		root->right = insertNode(root->right,x);
	return root;
}
void inorder(struct node *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}
void preorder(struct node *root)
{
	if(root)
	{
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node *root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->data);
	}
}
int treeMin(struct node *temp)
{
	if(temp == NULL)
		printf("\nTree is Empty");
	else
	{
		while(temp->left!=NULL)
			temp = temp->left;
	}
	return temp->data;
}
int treeMax(struct node *temp)
{
	if(temp == NULL)
		printf("\nTree is Empty");
	else
	{
		while(temp->right!=NULL)
			temp = temp->right;
	}
	return temp->data;
}
void successor(struct node *root)
{
	int s;
	if(root == NULL)
		printf("\nTree is Empty");
	else if(root->right != NULL)
	{
		s=treeMin(root->right);
		printf("\nSuccessor: %d",s);
	}
	else
		printf("\nNo Successor");
}
void predecessor(struct node *temp)
{
	int s;
	if(root == NULL)
		printf("\nTree is Empty");
	else if(root->left != NULL)
	{
		s=treeMax(root->left);
		printf("\nPredecessor: %d",s);
	}
	else
		printf("\nNo Predecesor");
}
void search(struct node *temp,int d)
{
	if(temp == NULL)
		printf("\nElement not found");
	else if(d==temp->data)
		printf("\nElement %d is found",d);
	else if(d<temp->data)
		search(temp->left,d);
	else
		search(temp->right,d);
}
int countNode(struct node *root)
{
	int c=1;
	if(root == NULL)
		return 0;
	else
	{
		c += countNode(root->left);
        c += countNode(root->right);
        return c;
	}
}
int internalNode(struct node *root)
{
	if(root==NULL)
		return 0;
	else if(root->left == NULL && root->right==NULL)
		return 1;
	else
		return (internalNode(root->left)+internalNode(root->right));
}
int externalNode(struct node *root)
{
	if(root==NULL)
		return 0;
	else if(root->left == NULL && root->right==NULL)
		return 1;
	else
		return (externalNode(root->left)+externalNode(root->right));
}
int heightOfBst(struct node *root)
{
	int ld,rd;
	if(root==NULL)
		return 0;
	else
	{
		ld = heightOfBst(root->left);
		rd = heightOfBst(root->right);
		
		if(ld > rd)
			return ld+1;
		else
			return rd+1;
	}
}
int deleteNode(struct node *temp,int n)
{
	struct node *ptr;
	if(temp == NULL)
		return 0;
	else if(n<temp->data)
		return deleteNode(temp->left,n);
	else if(n>temp->data)
		return deleteNode(temp->right,n);
	else
	{
		if(temp->left == NULL)
		{
			ptr = temp;
			temp = temp->right;
			free(ptr);
			return 1;
		}
		else if(temp->right == NULL)
		{
			ptr = temp;
			temp = temp->left;
			free(ptr);
			return 1;
		}
		else
		{
			ptr = temp->left;
			while(ptr->right != NULL)
				ptr = ptr->right;
			temp->data = ptr->data;
			return deleteNode(temp->left,ptr->data);
		}
	}
}
void deleteTree(struct node *root)
{
	if(root)
	{
		deleteTree(root->left);
		deleteTree(root->right);
		free(root);
		printf("Data Deleted : %d",root->data);
	}
}
void main()
{
	int input,ch,data,flag;
	printf("\t\t-------======Binary Search Tree======----------\n");
	do
	{
		printf("1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Tree Minimum");
		printf("\n6.Tree Maximum\n7.Successor\n8.Predecessor\n9.Search\n10.Count the Nodes");
		printf("\n11.Internal Nodes\n12.Height of Tree\n13.External Nodes");
		printf("\n14.Delete a node in Tree\n15.Delete Tree");
		printf("\nEnter your choice: ");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				printf("\nEnter data to insert: ");
				scanf("%d",&data);
				root = insertNode(root,data);
				break;
			case 2:
				inorder(root);
				break;
			case 3:
				preorder(root);
				break;
			case 4:
				postorder(root);
				break;
			case 5:
				data=treeMin(root);
				printf("\nTree Minimum: %d",data);
				break;
			case 6:
				data=treeMax(root);
				printf("\nTree Maximum: %d",data);
				break;
			case 7:
				successor(root);
				break;
			case 8:
				predecessor(root);
				break;
			case 9:
				printf("\nEnter data to Search: ");
				scanf("%d",&data);
				search(root,data);
				break;
			case 10:
				data = countNode(root);
				printf("\nNumber of Node is: %d",data);
				break;
			case 11:
				data = internalNode(root);
				printf("\nNumber of Internal Node is: %d",data);
				break;
			case 12:
				data = heightOfBst(root);
				printf("\nHeight of Binary tree is: %d",data);
				break;
			case 13:
				data = externalNode(root);
				printf("\nNumber of External Node is :%d",data);
				break;
			case 14:
				printf("\nEnter data to Delete: ");
				scanf("%d",&data);
				flag = deleteNode(root,data);
				if(flag == 1)
					printf("\nElement %d is deleted from tree",data);
				else
					printf("\nElement %d is not present in tree",data);
				break;
			case 15:
				deleteTree(root);
				printf("\nTree is Empty");
		}
		printf("\nContinue????: ");
		scanf("%d",&ch);
	}while(ch!=0);
}
/*
                -------======Binary Search Tree======----------
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Tree Minimum
6.Tree Maximum
7.Successor
8.Predecessor
9.Search
10.Count the Nodes
11.Internal Nodes
12.Height of Tree
13.External Nodes
14.Delete a node in Tree
15.Delete Tree
Enter your choice: 1

Enter data to insert: 25

Continue????: 1
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Tree Minimum
6.Tree Maximum
7.Successor
8.Predecessor
9.Search
10.Count the Nodes
11.Internal Nodes
12.Height of Tree
13.External Nodes
14.Delete a node in Tree
15.Delete Tree
Enter your choice: 1

Enter data to insert: 36

Continue????: 1
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Tree Minimum
6.Tree Maximum
7.Successor
8.Predecessor
9.Search
10.Count the Nodes
11.Internal Nodes
12.Height of Tree
13.External Nodes
14.Delete a node in Tree
15.Delete Tree
Enter your choice: 1

Enter data to insert: 14

Continue????: 1
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Tree Minimum
6.Tree Maximum
7.Successor
8.Predecessor
9.Search
10.Count the Nodes
11.Internal Nodes
12.Height of Tree
13.External Nodes
14.Delete a node in Tree
15.Delete Tree
Enter your choice: 1

Enter data to insert: 58

Continue????: 1
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Tree Minimum
6.Tree Maximum
7.Successor
8.Predecessor
9.Search
10.Count the Nodes
11.Internal Nodes
12.Height of Tree
13.External Nodes
14.Delete a node in Tree
15.Delete Tree
Enter your choice: 1

Enter data to insert: 42

Continue????: 1
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Tree Minimum
6.Tree Maximum
7.Successor
8.Predecessor
9.Search
10.Count the Nodes
11.Internal Nodes
12.Height of Tree
13.External Nodes
14.Delete a node in Tree
15.Delete Tree
Enter your choice: 1

Enter data to insert: 10

Continue????: 1
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Tree Minimum
6.Tree Maximum
7.Successor
8.Predecessor
9.Search
10.Count the Nodes
11.Internal Nodes
12.Height of Tree
13.External Nodes
14.Delete a node in Tree
15.Delete Tree
Enter your choice: 1

Enter data to insert: 11

Continue????: 1
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Tree Minimum
6.Tree Maximum
7.Successor
8.Predecessor
9.Search
10.Count the Nodes
11.Internal Nodes
12.Height of Tree
13.External Nodes
14.Delete a node in Tree
15.Delete Tree
Enter your choice: 1

Enter data to insert: 51

Continue????: 1
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Tree Minimum
6.Tree Maximum
7.Successor
8.Predecessor
9.Search
10.Count the Nodes
11.Internal Nodes
12.Height of Tree
13.External Nodes
14.Delete a node in Tree
15.Delete Tree
Enter your choice: 2
10      11      14      25      36      42      51      58
Continue????: 1
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Tree Minimum
6.Tree Maximum
7.Successor
8.Predecessor
9.Search
10.Count the Nodes
11.Internal Nodes
12.Height of Tree
13.External Nodes
14.Delete a node in Tree
15.Delete Tree
Enter your choice: 3
25      14      10      11      36      58      42      51
Continue????: 1
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Tree Minimum
6.Tree Maximum
7.Successor
8.Predecessor
9.Search
10.Count the Nodes
11.Internal Nodes
12.Height of Tree
13.External Nodes
14.Delete a node in Tree
15.Delete Tree
Enter your choice: 4
11      10      14      51      42      58      36      25
Continue????: 1
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Tree Minimum
6.Tree Maximum
7.Successor
8.Predecessor
9.Search
10.Count the Nodes
11.Internal Nodes
12.Height of Tree
13.External Nodes
14.Delete a node in Tree
15.Delete Tree
Enter your choice: 5

Tree Minimum: 10
Continue????: 1
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Tree Minimum
6.Tree Maximum
7.Successor
8.Predecessor
9.Search
10.Count the Nodes
11.Internal Nodes
12.Height of Tree
13.External Nodes
14.Delete a node in Tree
15.Delete Tree
Enter your choice: 6

Tree Maximum: 58
Continue????: 1
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Tree Minimum
6.Tree Maximum
7.Successor
8.Predecessor
9.Search
10.Count the Nodes
11.Internal Nodes
12.Height of Tree
13.External Nodes
14.Delete a node in Tree
15.Delete Tree
Enter your choice: 7

Successor: 36
Continue????: 1
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Tree Minimum
6.Tree Maximum
7.Successor
8.Predecessor
9.Search
10.Count the Nodes
11.Internal Nodes
12.Height of Tree
13.External Nodes
14.Delete a node in Tree
15.Delete Tree
Enter your choice: 1

Enter data to insert: 8

Continue????: 1
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Tree Minimum
6.Tree Maximum
7.Successor
8.Predecessor
9.Search
10.Count the Nodes
11.Internal Nodes
12.Height of Tree
13.External Nodes
14.Delete a node in Tree
15.Delete Tree
Enter your choice: 8

Predecessor: 14
Continue????: 1
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Tree Minimum
6.Tree Maximum
7.Successor
8.Predecessor
9.Search
10.Count the Nodes
11.Internal Nodes
12.Height of Tree
13.External Nodes
14.Delete a node in Tree
15.Delete Tree
Enter your choice: 9

Enter data to Search: 15

Element not found
Continue????: 1
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Tree Minimum
6.Tree Maximum
7.Successor
8.Predecessor
9.Search
10.Count the Nodes
11.Internal Nodes
12.Height of Tree
13.External Nodes
14.Delete a node in Tree
15.Delete Tree
Enter your choice: 9

Enter data to Search: 8

Element 8 is found
Continue????: 1
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Tree Minimum
6.Tree Maximum
7.Successor
8.Predecessor
9.Search
10.Count the Nodes
11.Internal Nodes
12.Height of Tree
13.External Nodes
14.Delete a node in Tree
15.Delete Tree
Enter your choice: 10

Number of Node is: 9
Continue????: 1
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Tree Minimum
6.Tree Maximum
7.Successor
8.Predecessor
9.Search
10.Count the Nodes
11.Internal Nodes
12.Height of Tree
13.External Nodes
14.Delete a node in Tree
15.Delete Tree
Enter your choice: 11

Number of Internal Node is: 3
Continue????: 1
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Tree Minimum
6.Tree Maximum
7.Successor
8.Predecessor
9.Search
10.Count the Nodes
11.Internal Nodes
12.Height of Tree
13.External Nodes
14.Delete a node in Tree
15.Delete Tree
Enter your choice: 12

Height of Binary tree is: 5
Continue????: 1
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Tree Minimum
6.Tree Maximum
7.Successor
8.Predecessor
9.Search
10.Count the Nodes
11.Internal Nodes
12.Height of Tree
13.External Nodes
14.Delete a node in Tree
15.Delete Tree
Enter your choice: 13

Number of External Node is :3
Continue????: 1
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Tree Minimum
6.Tree Maximum
7.Successor
8.Predecessor
9.Search
10.Count the Nodes
11.Internal Nodes
12.Height of Tree
13.External Nodes
14.Delete a node in Tree
15.Delete Tree
Enter your choice: 15
Tree is Empty
Continue????: 1
1.Insert
2.Inorder
3.Preorder
4.Postorder
5.Tree Minimum
6.Tree Maximum
7.Successor
8.Predecessor
9.Search
10.Count the Nodes
11.Internal Nodes
12.Height of Tree
13.External Nodes
14.Delete a node in Tree
15.Delete Tree
Enter your choice: 14

Enter data to Delete: 8

--------------------------------
*/
