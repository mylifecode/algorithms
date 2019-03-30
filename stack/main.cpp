#include<iostream>
#include"stack.h"

using namespace std;


int main()

{
stack<int> st1(10);
for(int i=0;i<10;i++)
{
 st1.push_back(i);
}
st1.isempty();
cout<<st1.top();
return 0;
}
