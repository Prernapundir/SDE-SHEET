/*Approach
1. Simple start from the root
2. Check root->value 
   if root->value greater, go to the left subtree
   else go to the right subtree
*/


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        if(root->val==val) return root;
        if(root->val>val){
            return searchBST(root->left,val);
        }
        return searchBST(root->right,val);
    }
};
