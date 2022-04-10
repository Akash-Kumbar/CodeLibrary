/*C++ Program for finding the kth Largest element in BST */
#include<bits/stdc++.h>
using namespace std;
/* A binary search tree node has data, pointer to left child 
and a pointer to right child */
struct Node
{
	int data;
	Node* left;
	Node* right;
	/*For Creating New Node*/
	Node(int val)
	{
		left = NULL;
		right = NULL;
		data = val;
	}
};
/*Insertion Function*/
Node* insert(Node* rt,int val)
{
	if(rt==NULL)
	{
		rt = new Node(val);
	}
	else if(val<=rt->data)
	{
		rt->left = insert(rt->left,val);
	}
	else
	{
		rt->right = insert(rt->right,val);
	}
	return rt;
}
/* Function for finding the kth Largest element in BST*/
Node* K_Largest(Node* rt,int &k)
{
	if(rt==NULL)
		return NULL;
	Node* right = K_Largest(rt->right,k);
	if(right!=NULL)
		return right;
	k--;
	if(k==0)
		return rt;
	return K_Largest(rt->left,k);
}
/*Inorder Traversal*/
void inorder(Node* rt)
{
	if(rt!=NULL)
	{
		inorder(rt->left);
		cout<<rt->data<<" ";
		inorder(rt->right);
	}
}
/* DRIVER FUNCTION */
int main()
{
	int k;
	/*In Insert function root is local thus why we are returning and storing root*/
	/*Initially the Root is NULL*/
	Node* root = NULL;
	root = insert(root,20);
	root = insert(root,8);
	root = insert(root,22);
	root = insert(root,4);
	root = insert(root,12);
	root = insert(root,10);
	root = insert(root,14);
	/* Inorder Traversal of BST is always in Ascending Order*/
	cout<<"Inorder Traversal of Tree is "<<endl;
	inorder(root);
	cout<<"\nEnter K to find the Kth Largest Element"<<endl;
	cin>>k;
	Node* temp;
	temp  = K_Largest(root,k);
	if(temp!=NULL)
		cout<<"The Kth Largest Element is "<<temp->data<<endl;
	else
		cout<<"Invalid Input"<<endl;
	return 0;
}
