#ifndef _STACK_H_
#define _STACK_H_
#include<iostream>
using namespace std;

template<class type>
class stack
{
 
 	
 	type* st;
 public:	
 	type size,Top;
   
     stack(type maxsize):size(maxsize),Top(-1)
    {
      st =new type[size];
      
    }

    ~stack()
    {
    	delete [] st;
    
    }

    bool isempty();  
    void pop();
    type top();
    void push_back(type data);
  
    

};




#endif
