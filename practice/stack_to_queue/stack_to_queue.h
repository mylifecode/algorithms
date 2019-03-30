#ifndef  stack_to_queue_h
#define  stack_to_queue_h

typedef struct node
{
	int data;
	node(int t_data=-1)
	{
		data=t_data;
	}

}node;

class stack
{
	public:
		int top;
		int size;
		node* p;
		stack();
		~stack();
		void push_back(int data);
		void pop();
		int get_top();
		bool is_empty();
		int get_len();
};

class queue
{
	public:
		int length;
		stack st1,st2;
		queue();
		~queue();
		void push_back(int data);
		void pop();
		int get_top();
		bool is_empty();
		int get_len();
};


#endif
