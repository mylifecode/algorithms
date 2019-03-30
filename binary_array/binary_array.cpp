
#include<iostream>

using namespace std;

bool check_num(int t[][4],int num)
{

	 int row,column;
	 row=0;
	 column=4;
	 while(row<=4&&column>=1)
	 {
	  if (t[row-1][column-1]>num)
	  {
	   column--;
	   }
	   else if (t[row-1][column-1]<num)
	   {
		row++;
		}
		else
	  {
	   cout<<"row,column:"<<row<<" "<<column<<endl;
	   return true;
	  }


	 }
	 if (row>4||column<0)
	  return false;

}

int main()

{

	int t[][4]={1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};

	bool flag=check_num(t,10);
	cout<<"flag:"<<flag<<endl;
	 return 0;
}
