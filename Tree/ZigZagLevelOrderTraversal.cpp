/*Approach 
1. Same like level order traversal
2. Use a variable which tells left to right or right to left print order
*/


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight=true;
        vector<vector<int>>ans;
        
        while(!q.empty()){
            int size=q.size();
            vector<int> temp(size);
            
            for(int i=0;i<size;i++){
                TreeNode* f=q.front();
                q.pop();
                int index=leftToRight?i:size-1-i;
                temp[index]=f->val;
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            ans.push_back(temp);
            leftToRight=!leftToRight;
        }
        return ans;
    }
};
