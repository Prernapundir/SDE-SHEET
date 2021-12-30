/*
1. Check if root node is lesser , than go to right subtree
2. If root node is greater , than go to left subtree
3. When reach at the end , the insert the node 
*/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val);
        }
        if(root->val>=val){
           root->left=insertIntoBST(root->left,val);
        }else{
            root->right=insertIntoBST(root->right,val);
        }
        return root;
    }
};
