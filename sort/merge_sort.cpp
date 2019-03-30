#include<iostream>
#include<vector>
using namespace std;


void merge(int left1,int right1,int left2,int right2,vector<int> &V)
{
	int i=left1,j=left2;
	vector<int> tmp;
	while(i<=right1&&j<=right2)
	{
		if(V[i]<=V[j])
		{
			
			tmp.push_back(V[i]);
			i++;
		}
		else
		{

			tmp.push_back(V[j]);
			j++;
		
		}
	}
	if(i>right1)
	{
	   for(;j<=right2;j++)
		tmp.push_back(V[j]);
    }
	else
	{

      for(;i<=right2;i++)
		tmp.push_back(V[i]);
    }
		
	
	for(int i=left1;i<=right2;i++)
	{
		V[i]=tmp[i-left1];
	}
	
}

void merge_sort(int left,int right,vector<int> &V)
{
	if(left>right)
		return;
		
	if(left<right)
	{
		int mid=(left+right)/2;	
		merge_sort(left,mid,V);
	    merge_sort(mid+1,right,V);
	    merge(left,mid,mid+1,right,V);
	}


}



int main(int argv,char* argc[])
{
	int a[]={9,8,6,2,6,8,34,4,3,1};
	int n=sizeof(a)/sizeof(int);
	vector<int> V(a,a+n);
	merge_sort(0,n-1,V);
	vector<int>::iterator it;
	for(it=V.begin();it!=V.end();it++)
	{
		cout<<*it<<" ";
	}
	return 0;
}



