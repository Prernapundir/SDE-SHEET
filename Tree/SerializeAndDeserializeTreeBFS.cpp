/*Approach
1.Use bfs , Its basically a design problem.Just a normal implementation of bfs
2. One improvement{Can use getline and stringstream}
3. For serialize do the level order traversal and convert binary tree to the string
4. To deserialize , convert string back to the binary tree using level order traversal.
*/

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       if(!root) return "";
       queue<TreeNode*> q;
        q.push(root);
        string s="";
        
        while(!q.empty()){
            int size=q.size();
            
            for(int i=0;i<size;i++){
                TreeNode* f=q.front();
                q.pop();
                if(f==NULL){
                    s+="#,";
                    continue;
                }else {
                    s+=to_string(f->val)+",";
                }
                if(f){
                    q.push(f->left);
                    q.push(f->right);
                }
            }
        }
        return s;
    }
    
    string getString(string s,int &i){
        string st;
        while(s[i]!=','){
           st+=s[i];
           i++;
        }
        i++;
        return st;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if(s.size()==0) return NULL;
        queue<TreeNode*> q;
        int i=0;
        string rs=getString(s,i);
        TreeNode* root=new TreeNode(stoi(rs));
        q.push(root);
      
        
        while(!q.empty() and i<s.size()){
            TreeNode* node=q.front();
            q.pop();
            rs=getString(s,i);
            if(rs=="#"){
                node->left=NULL;
            }else{
                node->left=new TreeNode(stoi(rs));
                q.push(node->left);
            }
            rs=getString(s,i);
            if(rs=="#"){
                node->right=NULL;
            }else{
                node->right=new TreeNode(stoi(rs));
                q.push(node->right);

            }
        }
        return root;
        
    }
};
