#include"stack.h"
#include<iostream>

using namespace std;

template<class type>
void stack<type>::push_back(type data)
{
 if(Top<size-1)
 {
  st[++Top]=data;
 }
 else
 {
 cout<<"stack is full!"<<endl;
 }

}

template<class type>
bool stack<type>:: isempty()
{

 return Top==-1;
}

template<class type>
void stack<type>:: pop()
{
	if(Top>=0)
	{
	 Top--;
	}
}
template<class type>
type  stack< type>::top()
{
	if (Top>=0)
	{
	return st[Top];

	}
	else
	{
	 cout<<"empty!"<<endl;
	 return;
	}
}


