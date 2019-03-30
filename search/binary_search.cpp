#include<iostream>
#include<vector>

using namespace std;

template<typename T>
bool binary_search(vector<T> &data, T a)
{
	int low=0,high=data.size()-1;
	T mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(data[mid]==a)
			return true;
		else if(data[mid]<a)
			low=mid+1;
		else
			high=mid-1;

	}
	if(low>high)
	{
		cout<<"data does not exist!"<<endl;
		return false;
	}
}


int main(int argc,char*argv[])
{	
	int a[]={5,6,7,13,667};
	int n=sizeof(a)/sizeof(int);
	vector<int> v(a,a+n);
	int t;
	cout<<"input a number:";
	cin>>t;
	cout<<endl;
	bool flag=binary_search(v,t);
	if(flag)
	cout<<"successful"<<endl;
	else
	cout<<"fault!"<<endl;
	return 0;
}
