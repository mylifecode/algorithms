#include"stack_to_queue.h"
#include<iostream>


stack::stack()
{
	size=100;
	node* p=new node[size];
	top=-1;
}

stack::~stack()
{
	delete[] p;
}

void stack:: push_back(int data)
{
	if(top+1<size)
	{
		p[++top].data=data;
	}
	
}

void stack:: pop()
{
	if(top>-1)
	{
		top--;
	}
}

int stack:: get_top()
{
	if(top>-1)
	{
		return p[top].data;
	}
}

bool stack:: is_empty()
{
	if(top>-1)
		return false;
	else
	{
		return true;
	}
}

int stack:: get_len()
{
	return top+1;
}

queue::queue()
{
 	length=0;
}

queue::~queue()
{

}

void queue::push_back(int data)
{
	int n_len=st1.get_len();
	if(n_len<st1.size)
	{
		st1.push_back(data);
		length++;
	}

}

void queue::pop()
{
	int n_len=st2.get_len();
	if(n_len>0)
	{
		st2.pop();
		length--;
	}
	else if(n_len==0&& st1.get_len())
	{
		while(!st1.is_empty())
		{
			int t_data=st1.get_top();
			st2.push_back(t_data);
			st1.pop();
		}
		st2.pop();
		length--;
	}
	

}

int queue::get_top()
{
	int n_len2=st2.get_len();
	if(n_len2)
	{
		return st2.get_top();
	}
	else if(n_len2==0&&st1.get_len())
	{
		while(!st1.is_empty())
		{
			st2.push_back(st1.get_top());
			st1.pop();
		}
		return st2.get_top();
	}
}

bool queue::is_empty()
{
	if(get_len())
		return false;
	else
		return true; 

}

int queue::get_len()
{
	return st1.get_len()+st2.get_len();

}


 
