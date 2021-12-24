/* BFS Approach
1. Make a queue and push src node with a NULL delimiter
2. Take a front node of queue, check if it's delimiter or not
3. If delimiter print the level till now  else push left and right node of front node if exists.
*/


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q ;
        vector<vector<int>>ans;
        vector<int> temp;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            TreeNode* f=q.front();
            q.pop();
            if(f==NULL){
                ans.push_back(temp);
                temp.clear();
                if(!q.empty()) q.push(NULL); 
            }else{
                temp.push_back(f->val);
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }  
        }
        return ans;
    }
};
