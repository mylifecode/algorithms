void construct(int *pre_order,int* in_order,int length)
{
  if(pre_order=NULL||in_order==NULL||length==0)
  {
   cout<<"isempty!"<<endl;
  }
  construct_core(pre_order,pre_order+length-1,in_order,in_order+length-1); 

}

typedef struct Tree_Node
{
 int data;
 Tree_Node* left_root;
 Tree_Node* right_root;
 Tree_Node(int t_data):data(t_data),left_root(NULL),right_root(NULL) {};

};


Tree_Node* construct_core(int* pre_order,int* end_pre_order,int *in_order,int* end_in_order)
{
 Tree_Node *root=new Tree_Node(pre_order[0]);
 
 int* start_in_order=in_order;
 while(start_in_order<=end_in_order&& start_in_order->data!=pre_order[0])
 {
   start_in_order++;
 }
 int left_length=start_in_order-in_order;
 if(left_length>0)
 {
 root->left=construct_core(pre_order+1,pre_order+left_length,in_order,in_order+left_length-1);
 }
 if(pre_order+left_length<end_pre_order)
 root->right=construct_core(pre_order+left_length+1,end_pre_order,in_order+left_length+1,end_in_order);
   return root;
}
