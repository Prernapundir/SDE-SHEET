/*Approach
1. Print the root node
2. Go to the left subtree
3. Go to the right subtree
*/


class Solution {
public:
    void recur(TreeNode* root,vector<int>&ans){
        if(!root) return;
        ans.push_back(root->val);
        recur(root->left,ans);
        recur(root->right,ans);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        recur(root,ans);
        return ans;
    }
};
