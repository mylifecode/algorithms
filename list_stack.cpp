#include<iostream>
using namespace std;
typedef struct node
{
	int data;
	node* next;
	node(int t_data):data(t_data),next(NULL) {}
}node;
class list_stack
{
	public:
		node* top;
		void push(int data);
		void pop();
		int Top();
		bool empty();
		
	list_stack()
	{
		top=NULL;
	}
	~list_stack()
	{
		delete top;
	}
	
};

void list_stack::push(int data)
{
	if(!top)
	{
		top=new node(data);
	}
	else
	{
		node* p=new node(data);
		p->next=top;
		top=p;
	}
}

void list_stack::pop()
{
	if(top)
	{
		node *p=top;
		top=top->next;
		delete p;
	}
	else
	{
		cout<<"empty!"<<endl;
	}
}
int list_stack::Top()
{
	
 	if(top)
 	{
 		return top->data;
 	}

}
bool list_stack::empty()
{

	if(top)
		return true;
	else
		return false;
}


int main()
{
	list_stack st;
	for(int i=0;i<10;i++)
	{
	  st.push(i);
	}
	for(int i=0;i<10;i++)
	{
		cout<<st.Top()<<" ";
	    st.pop();
	}
	
	return 0;
}
