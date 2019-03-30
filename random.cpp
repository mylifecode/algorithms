#include<iostream>
#include<stdlib.h>
using namespace std;
#define maxsize 100000000
void count_pi()
{
	srand(time(0));
	int cnt=0;
	for(int i=0;i<maxsize;i++)
	{
		int x=rand()%100/(double)101;
		int y=rand()%100/(double)101;
		cout<<"x"<<x<<" "<<y<<endl;
		if(x*x+y*y<1)
		cnt++;
	}
	double p=cnt/maxsize*4;
    cout<<p<<endl;

}

int main()
{
	count_pi();
	return 0;
}
