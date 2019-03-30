#include<iostream>
#include<stack>
using namespace std;
typedef int Data;
typedef struct Node
{
 Data data;
 Node* pnext;
 Node(Data t_data=-1): data(t_data),pnext(NULL) {};

}Node;


class list
{
 public:
     Node *phead;
     int length;
 list()
  {
   phead=new Node;
   length=0; 
   }
 void add_node(Data t_data)
{
  Node* pnode =phead;
  if(!pnode->pnext)
  {
   pnode =new Node(t_data);
   phead->pnext=pnode;
   length++;
cout<<"add successfull"<<endl;
   }
  else
  {
   cout<<"pnode:"<<pnode<<endl;
   while(pnode->pnext) 
   {
    pnode=pnode->pnext;
   }  
   Node*p=new Node(t_data);
   pnode->pnext=p;
   length++;
  cout<<"ddd"<<endl;
  }

}
 void print()
{
 Node* p=phead->pnext;
cout<<"result:";
 while(p)
 {
  cout<<p->data<<" ";
  p=p->pnext;
 }
cout<<endl;

}

void res_print()
{
 stack<Node*> st;
 Node *p=phead->pnext; 
while(p)
{
 st.push(p);
 p=p->pnext;
}

cout<<"result:";
while(!st.empty())
{
 Node* tmp=st.top();
 cout<<tmp->data;
 st.pop();
}
cout<<endl;
}

int get_len()
{
return length;
}

####递归方法逆序打印链表
void reserve_print(Node* t_phead)
{
	
	Node *p=t_phead;
	if (p==phead)
		p=phead->pnext;
	if(p)
	{
		if(p->pnext)
		{
		
		 reserve_print(p->pnext);
		}	
	    cout<<p->data<<" ";
	}
}

};

int main()
{
	list list1;
	for(int i=0;i<10;i++)
	{
		list1.add_node(i);
	}
		list1.print();
		list1.res_print();

		list1.reserve_print(list1.phead);
return 0;
}

