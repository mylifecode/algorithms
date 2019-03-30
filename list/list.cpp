#include<iostream>
#include<string>

using namespace  std;
class person
{
public:
 char* name;
 int age;
 person(char *t_name,int t_age):name(t_name),age(t_age) {};
 person()
 {};
int Get_age()
{
 return age;
} 
char* Get_name()
{
  return name;
}
};

struct node
{
  person *p;
  node *p_next;

  node()
  {
   p=NULL;
   p_next=NULL;
  }
  node(char *t_name,int t_age)
{
  p=new person(t_name,t_age);
  p_next=NULL;

}
};

node *head=new node;

void add_node(char* t_name,int t_age)
{
  node *n=new node(t_name,t_age);

  if (!head->p_next)
  {
    head->p_next=n;
   }
  else
  {
   n->p_next=head->p_next;
   head->p_next=n;

 }
}
void print()
{
  node* pn=head->p_next;
  while(pn)
  {
   cout<<pn->p->name<<" "<<pn->p->age<<endl;
   pn=pn->p_next;
}
}

int main()
{
 char name[]="aa";
 add_node(name,22);
 print();

return 0;
}
