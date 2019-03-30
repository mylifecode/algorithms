#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	node *next;
	//node(int t_data): data(t_data),next(NULL) {}

}Node;



void create_list(node** head)
{
	if(head)
	{
		 (*head)=new node;
		(*head)->next=NULL;
	}
    for(int i=0;i<10;i++)
    {
 		node* p=new node;
    	p->data=i;
    	p->next=(*head)->next;
        (*head)->next=p;
    }
}


void print(node* head)
{
	node* p=head->next;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}

}

void rec_print(node *head)
{
	if(head)
	{
		if(head->next)
		{
			rec_print(head->next);
		
		}
		cout<<head->data<<" ";
	}

}

int main()
{
	node* head;
	create_list(&head);
	cout<<"result:";
	print(head);
	cout<<endl;
	rec_print(head->next);
	return 0;
}
