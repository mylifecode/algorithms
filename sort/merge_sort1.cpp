#include<iostream>
using namespace std;


void merge_sort(int* a,int n)
{
	int*R =new int[n];
	int k=1;
	while(k<n)
	{
		dist_merge(a,k,n);
		k=2*k;
		dist_merge(a,k,n);
	    k=2*k;
	
	}



}

void dist_merge(int*a,int s,int n)
{
	int i=1;
	while(i<=n-2*s+1)
	{
		l=i-1+s;
		r=i-1+2*s;
		merge(a,l,r,s);
		i=i+2*s;
	
	}
    if(i<n-s+1)
    {
    	merge(a,i,n,s);
    
    }


}



int main()
{




	return 0;
}
