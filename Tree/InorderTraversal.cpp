
/*Approach 
1. Go to the left subtree
2. Print the root node
3. Go to the right subtree
*/

class Solution {
public:
    void recur(TreeNode* root,vector<int>&ans){
        if(!root) return;
        recur(root->left,ans);
        ans.push_back(root->val);
        recur(root->right,ans);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        recur(root,ans);
        return ans;
    }
};
