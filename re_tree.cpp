#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	node* left;
	node* right;
	node(int t_data=-1):data(t_data),left(NULL),right(NULL){}

}node;

node* re_create(int*a,int*b,int left1,int right1,int left2,int right2)
{  
   //root=&root
	int tmp=a[left1];
	node* root=new node(tmp);
	if(left1==right1&&left2==right2)
		return  root;
	
	int value=root->data;
	int i=left2;
	while(i<=right2&&b[i]!=value)
		i++;
	int length=i-left2;
	if(length>0)
		root->left=re_create(a,b,left1+1,left1+length,left2,left2+length);
	if(length<right1-left1)
		root->right=re_create(a,b,left1+length+1,right1,left2+length+1,right2);	
    return root;
}


void pre_order(node* root)
{
	if(root)
	{
		cout<<root->data<<endl;
		pre_order(root->left);
		pre_order(root->right);
		
	}
	


}

void h_order(node* root)
{
	if(root)
	{
	
		h_order(root->left);
		h_order(root->right);
		cout<<root->data<<" ";
	}
	


}

int main()
{
	int a[]={1,2,4,7,3,5,6,8};
	int b[]={4,7,2,1,5,3,8,6};
	node* root=NULL;
	root=re_create(a,b,0,7,0,7);
	h_order(root);
	return 0;
}

