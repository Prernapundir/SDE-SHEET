

Node *helper(Node*l1,Node*l2){
    Node* temp=new Node(0);
    Node* dummy=temp;
    
    while(l1!=NULL and l2!=NULL){
        if(l1->data>l2->data){
            temp->bottom=l2;
            l2=l2->bottom;
        }else{
            temp->bottom=l1;
            l1=l1->bottom;
        }
        temp=temp->bottom;
    }
    
   if(l1!=NULL) temp->bottom=l1;
   else temp->bottom=l2;
   return dummy->bottom;
}
    
Node *flatten(Node *root)
{
   if(!root or !root->next) return root;
   
   root->next=flatten(root->next);
   root=helper(root,root->next);
   return root;
}
