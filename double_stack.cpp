#include<iostream>
using namespace std;
typedef int DATA;
#define maxsize 100000
class double_stack
{
	public:
		DATA top1;
		DATA top2;
		DATA size;
		DATA *p;
   double_stack(DATA t_size)
   {	
   	    if(t_size>maxsize)
   	    	size=maxsize;
   		size=t_size;
   		p=new DATA[size];
   		top1=-1;
   		top2=size;
   }
   ~double_stack()
   {
   		delete []p;
   }
   void push(DATA e,DATA num)
   {
    	if(top1+1==top2)   //full
    	{
    		cout<<"full"<<endl;
    		return;
    	}
        if(num==1)
        {
        	p[++top1]=e;
        }
        else
        {
        	p[--top2]=e;
        }
   
   }
   
 void pop(DATA num)
  {
	   	 if(num!=1&&num!=2)
	   	 {
	   	 	cout<<"input error!"<<endl;
	   	 	return;
	   	 }
		if(num==1)
	   	 {
	   	 	if(top1>-1)
	   	 	{
	   	 		top1--;
	   	 	}	
	   	 	
	   	 }
	   	 else 
	   	 {
	   	 	if(top2<size)
	   	 	{
	   	 		top2++;
	   	 	}
	   	 }
   
   }
   bool empty()
   {
     if(top1==-1&&top2==size)
     	
     	return true;
     	
     else
     
     	return false;
   }
   
   DATA top(DATA num)
   {
 
		if(num==1)
	   	 {
	   	 	if(top1>-1)
	   	 	{
	   	 		return p[top1];
	   	 	}	
	   	 	
	   	 }
	   	 else if(num==2)
	   	 {
	   	 	if(top2<size)
	   	 	{
	   	 		return p[top2];
	   	 	}
	   	 }
	   	 
   }
};


int main()
{
	double_stack st(100);
	for(int i=0;i<10;i++)
	{
		st.push(i,1);
		st.push(10-i,2);
	}
	cout<<"stack1:"<<endl;
	cout<<"top1:"<<st.top1<<" "<<st.top2<<endl;
    for(int i=0;i<10;i++)
    {
      cout<<st.top(1)<<" ";
      st.pop(1);
    }
    cout<<endl;
    cout<<"stack2:"<<endl;
   for(int i=0;i<10;i++)
    {
      cout<<st.top(2)<<" ";
      st.pop(2);
    }

	return 0;
}
