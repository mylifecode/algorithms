#include<iostream>
#include<cstdlib.h>
#include<ctime>
#include<stdlib.h>
using namespace std;
#define maxsize 100000
#define x 20
#define y 30



typedef struct node
{
	int x;
	int y;
	char direction;
	node* next;
	node(int t_x,int t_y,char dir): x(t_x),y(t_y),direction(dir),next(NULL) {}
}node;


class stack
{
	public:
	int top;
	node* st;
	int size;
	stack(int t_size)
	{
		if(maxsize<t_size)
		{
			size=maxsize;
		}
		size=t_size;
		st=new node[size];
		top=-1;
	}
	void push(int x,int y,char direction)
	{
		if(top>=size)
		{
			cout<<"full!"<<endl;
		}
		else
		{
			node p(x,y,direction);
			st[++top]=p;
		}
	}
	void pop()
	{
		if(top<=-1)
		{
			cout<<"empty!"<<endl;
		}
		else
		{
			top--;
		}
	
	}

};

class game
{
	public:
		int map[x][y];
		stack st(100);
		game()
		{
			create_map();
			bool flag =confirm();
			while(!flag)
			{
				create_map();
				flag =confirm();
			}
		}
		~game()
		{
	
		}
		void create_map()
		{
		  srand((unsigned)time(NULL));
	      for(int i=0;i<x;i++)
	      	for(int j=0;j<y;j++)
	      	{
	      		map[i][j]=1;
	      	
	      	}
	      map[0][1]=0;
	      map[x-1][y-2]=0;
	      for(int i=1;i<x-1;i++)
	      for(int j=1;j<y-1;j++)
	      	{
	      		int temp=(int)rand()%1;
	      		map[i][j]=temp;
	      	}
		}
		bool confirm(int t_x,int t_y,char dir)
		{
	     	if(t_x==x-1&&t_y==y-2)
	     	{
	     		st.push(t_x,t_y,dir); 
	     		return true;
	     	}
	     	else
	     	{
	     		bool flag=false;
	     		st.push(t_x,t_y,dir);  
	     		for(int i=0;i<4;i++)
	     		{
	     			t_x=t_x+x1;
	     			t_y=t_y+y1;
	     			dir=dir1;
	     			if(0<=t_x<=x-1&&0<=t_y<=y-1&&path[t_x][t_y]==0)
	     			{	
	     				path[t_x][t_y]=1;
	     				flag=confirm(t_x,t_y,dir);
	     				if(flag)
	     					break;
	     			}
	     		
	     		}
                if(!flag)
                {
                	st.pop();
                }
                return flag;
	     	}
	     	
	
		}
		void auto_game()
		{
	
		}
		void self_game()
		{
	
		}
        void show_map()
        {
        	for(int i=0;i<x;i++)
        	for(int j=0;j<x;j++)
        	{
        		if(map[i][j]==0)
        			cout<<"  ";
        		else if(map[i][j]==1)
        			cout<<"fangk";
        	    else if(map[i][j]==2)
        			cout<<"fangk";
        	    else if(map[i][j]==3)
        			cout<<"fangk";
        	   else if(map[i][j]==4)
        			cout<<"fangk";	
        	   else if(map[i][j]==5)
        			cout<<"fangk";
        	   else if(map[i][j]==6)
        	  		cout<<"fangk";
        			
        			
        			
        	}
        }
	
};

void meau()
{
	system("clear");
	cout<<"       1 查看地图              "<<endl;
	cout<<"       2 自动游戏              "<<endl;
	cout<<"       3 手动游戏              "<<endl;
	cout<<"       4 退出                 "<<endl;
	char s=getchar();
	game g;
	switch(s):
	{
		case('1'):
			g.show_map();
			break;
		case('2'):
			g.auto_game();
			break;
		case('3'):
			g.self_game();
			break;
		default:
			g.exit();
			break;
	}

}

int main(int argc,char** argv)
{
	meau();
	return 0;
}
