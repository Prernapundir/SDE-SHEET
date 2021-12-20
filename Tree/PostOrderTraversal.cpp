/*Approcah
1. Go to the left subtree first
2. Go to the right subtree then
3. Print the root node
*/

class Solution {
public:
  
      void recur(TreeNode* root,vector<int>&ans){
        if(!root) return;
        recur(root->left,ans);
        recur(root->right,ans);
        ans.push_back(root->val);
        return;
    }
    vector<int>  postorderTraversal(TreeNode* root) {
        vector<int>ans;
        recur(root,ans);
        return ans;
    }
};
