/*Approach
1. Push the root node to the queue
2. Iterate over the size of queue till !q.empty()
3. For let view print first value of i(reverse in case of right view , there we have to print last value)
4. Push left and right child of tree in queue if exits.
*/


class Solution {
public:
    vector<int> leftSideView(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* f=q.front();
                if(i==0){
                    ans.push_back(f->val);
                }
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                q.pop();
            }
        }
        return ans;
    }
};
