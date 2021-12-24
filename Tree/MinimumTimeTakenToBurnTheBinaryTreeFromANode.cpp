/*Approcah
1. Same like {Find All Nodes at diatnce k from a node}
*/


class Solution {
  public:
  void find_parent(Node*root, unordered_map<Node*,Node*>& m){
        queue<Node*> q;
        q.push(root);
        m[root]=root;
        while(!q.empty()){
            Node* f=q.front();
            q.pop();
            if(f->left) {
                q.push(f->left);
                m[f->left]=f;
            }
            if(f->right){
                q.push(f->right);
                m[f->right]=f;
            }
        }
        return;
    }
    
    Node* findTargetNode(Node* root,int target){
        if(!root) return NULL;
        if(root->data==target){
            return root;
        }
        Node* left= findTargetNode(root->left,target);
        Node*right=findTargetNode(root->right,target);
        return left?left:right;
    }
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*,Node*> parent;
        find_parent(root,parent);
        vector<int> ans;
        queue<Node*> q;
        Node* target_node=findTargetNode(root,target);
        
        
        q.push(target_node);
        unordered_map<Node*,bool> vis;
        vis[target_node]=true;
        int dis=0;
        
        while(!q.empty()){
            int size=q.size();
            
            for(int i=0;i<size;i++){
                Node* f=q.front();
                Node* p=parent[f];
                if(f->left and vis.find(f->left)==vis.end()){
                    q.push(f->left);
                    vis[f->left]=true;
                }
                if(f->right and vis.find(f->right)==vis.end()){
                    q.push(f->right);
                    vis[f->right]=true;
                }
                if(!vis[p]){
                    q.push(p);
                    vis[p]=true;
                }
                q.pop();
            }
            dis++;
        }
        return dis-1;
    }
};
