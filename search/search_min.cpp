#include<iostream>
#include<vector>
using namespace std;

int order_list(int* a,int n)
{
	int result=0;
	for(int i=1;i<n;i++)
	{
		if(a[result]>a[i])
			result=i;
	
	}
	return result;
}

int min_search(int *a,int n)
{
	int left=0,right=n-1;
	int mid=left;
	while(a[left]>=a[right])
	{
		if(left+1==right)
		{	
			mid=right;
			break;
		}
	    mid=(left+right)/2;
	    if(a[mid]==a[left]&&a[mid]==a[right])
	    {
	    	cout<<"ss"<<endl;
	    	mid=order_list(a,n);
	    	break;
	    }
		if(a[mid]>a[left])
			left=mid;
		else if(a[mid]<a[right])
			right=mid;
		
	
	}
	return a[mid];

}

int main()
{
	int a[]={1,1,1,0,1,1};
	
	int n=sizeof(a)/sizeof(int);
	//vector<int> v(a,a+n);
	int t=order_list(a,n);
	cout<<"t:"<<a[t]<<endl;
	int min=min_search(a,n);
	cout<<"min:"<<" "<<min<<endl; 
	return 0;
	
	

}
