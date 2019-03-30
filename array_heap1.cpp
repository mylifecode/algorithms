#include<iostream>
using namespace std;

template<class T>
class array
{
	public:
		array(int t_num);
		~array();
		const T& operator[] (int) const;
		T& operator[] (int);
		int getlen()const;
	private:
		int num;
		T* A;
};

template<class T>
array<T>::array(int t_num)
{
	num=t_num;
	A=new T[num]; 
}

template<class T>
array<T>::~array()
{
	delete[] A;
}

template<class T>
const T& array<T>:: operator[] (int t_num) const
{
	if(t_num<0||t_num>=num)
	{
		cout<<"input error!"<<endl;
	}
	else
	{
		return A[t_num];
	}

}

template<class T>
T& array<T>::operator[](int t_num)
{
	if(t_num>=num||t_num<0)
	cout<<"input error!"<<endl;
	
	return A[t_num];
}

template<class T>
int array<T>::getlen() const
{
	return num;
}

template<class T>
ostream & operator<< (ostream &out,const array<T>& A)
{
	for(int i=0;i<A.getlen();i++)
		out<<A[i]<<endl;
	return out;
}

int main()
{
	array<int> A(10);
	for(int i=0;i<10;i++)
	{
		A[i]=2*i;
	}
	cout<<A<<endl;
	return 0;
}

