#include<iostream>
#include"time.h"
#include"stdlib.h"
#include<algorithm>
using namespace std;

bool compare(const int& a,const int &b)
{
	return a<b;

}

void find(int* arr,int n,int num,int* index)
{
	sort(arr,arr+n,compare);
	int i=0,j=n-1;
	while(i<j)
	{
		int sum=*(arr+i)+*(arr+j);
		if(sum<num)
		{
			while(++i<j&&*(arr+i)==*(arr+i-1)){}
		}
		else if(sum>num)	
		{
			while(i<++j&&*(arr+j)==*(arr+j-1)) {}	
		
		}
		else
			break;
	}
	if(i<j)
	{
		index[0]=i;
		index[1]=j;
	}
}

int main()
{
	int arr[10];
	srand(time(0));
	for(int i=0;i<10;i++)
		arr[i]=rand()%100;
	int index[2]={0,0};
	int num=rand()%100;
	find(arr,10,num,index);	
	for(int i=0;i<10;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
   cout<<"num:"<<num<<" "<<index[0]<<" "<<index[1]<<endl;
	return 0;
}
