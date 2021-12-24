/*Approach
1. It's a BST , so we can terminate one side
2. If root value is greater than p and q, go to the left subtree
3. If root value is less than p and q , go to th right subtree
4. Else return root { i.e p and q present , in its left and right }
*/


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val>q->val and root->val>p->val){
            return lowestCommonAncestor(root->left,p,q);
        }else if(root->val<p->val and root->val<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }
};
