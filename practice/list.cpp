#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	node *next;
	node(int t_data=-1): data(t_data),next(NULL) {};
}node;

class list
{
	public:
		node* head;
		int length;
		list():head(new node),length(0) {};
		void insert(int data);
		void delete_node(int num);
		void look(int num);
		bool isempty();
		void show();
		int get_len();
};


void list:: insert(int data)
{
	node* p=new node(data);
	node* tmp=head->next;
	head->next=p;
	p->next=tmp;
	length++;
}

void list:: delete_node(int num)
{
	node*p=head;
	for(int i=0;i<num-1;i++)
	{
		p=p->next;
	}
	node* temp=p->next;
	p->next=p->next->next;
	delete temp;
	length--;
}

void list::look(int num)
{
	node*p=head->next;
	for(int i=0;i<num;i++)
	{
		p=p->next;
	}
	cout<<"num:";
	cout<<p->data<<endl;
}

bool list::isempty()
{
	if(!length)
		return false;
	else
		return true;
}

void list:: show()
{
	node* p=head->next;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;	
}

int list::get_len()
{
	return length;
}


int main()
{
	list list1;
	for(int i=0;i<10;i++)
	{
		list1.insert(10-i);
	}
	list1.show();
	list1.delete_node(2);
	list1.show();
	cout<<list1.get_len();
	cout<<endl;
	cout<<list1.isempty();
	return 0;

}


