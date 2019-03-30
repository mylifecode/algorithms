#include<iostream>
#include"stack_to_queue.h"

using namespace std;


int main()
{
	queue q1;
	for(int i=0;i<10;i++)
	{
		q1.push_back(10-i);	
    }
	while(!q1.is_empty())
	{
		int tmp=q1.get_top();
		cout<<"tmp:"<<tmp<<endl;	
		q1.pop();
	}

	return 0;
}
