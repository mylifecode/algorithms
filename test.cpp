#include<iostream>

using namespace std;

int main()
{
  	int* a;
  	
  	cout<<"a:"<<a<<" "<<sizeof(a)<<endl;
  	int**p=&a;
  	
    a=new int;
  	cout<<"a:"<<a<<" "<<sizeof(a)<<endl;
	return 0;
}
