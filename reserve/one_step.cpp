#include<iostream>

using namespace std;


int fn(int n)
{
 if (n==1)
 	return 1;
 else if(n==2)
 	return 2;
 else
 	return fn(n-1)+fn(n-2);
}


int main()

{
int n=40;
cout<<fn(n)<<endl;

return 0;
}
