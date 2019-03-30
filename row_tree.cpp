#include<iostream>

using namespace std;

typedef struct tnode
{
	int data;
	tnode* left;
	tnode* right;
	tnode(int t_data=-1):data(t_data),left(NULL),right(NULL) {}
}tnode;


typedef struct node
{
	tnode* ad;
	node* next;

	node(tnode* t_ad=NULL):ad(t_ad),next(NULL){}

}node;

class queue
{
	private:
		int size;
		node* top;
		node* tail;
		int length;
	public:
		queue(int t_size=100)
		{
			size=t_size;
			top=NULL;
			tail=NULL;
			length=0;
		}
		void push_back(tnode* ad)
		{
			node* tmp=new node(ad);
			if(!top)
			{
				top=tmp;
				length++;
				tail=top;
			}
			else
			{
				if(length<size)
				{
					tail->next=tmp;
					tail=tmp;
					length++;
				}
			
			
			}
			
		}
		
	  	 void pop_back()
	  	 {
	  	 	if(length>0)
	  	 	{
	  	 		node* tmp=top;
	  	 		top=top->next;
	  	 		delete tmp;
	  	 		length--;
	  	 	}
	  	 	
	  	 
	  	 }
	  tnode* get_top()
	  {
	  	return top->ad;
	  
	  }
};





void row_tree(queue q)
{
	tnode* tmp=q.get_top();
	cout<<tmp->data<<" ";
	if(tmp->left)
	q.push_back(tmp->left);
	if(tmp->right)
	q.push_back(tmp->right);


}


void create_tree(tnode** root,int *p,int* end)
{
	if(!(*root))
		(*root)=new tnode(*p);
	if(end>p)
		{
		if(*p>(*root)->data)
		{
			create_tree(&((*root)->left),p++,end);
		}
	 	else
	 	{
	 		create_tree(&((*root)->right),p++,end);
	 	}
	}
}

void pre_order(tnode* root)
{
	if(root)
	{
		cout<<root->data<<" ";
		pre_order(root->left);
		pre_order(root->right);
	}
}

int main()
{
	tnode* root;
	int a[]={1,2,3,4,5,6,7,8};
	int n=sizeof(a)/sizeof(int);
	create_tree(&root,a,n+a);
	pre_order(root);
	//queue q;
	//q.push_back(root);
	//row_tree(q);
	return 0;
}
