
/* Brute Force 
1. Find the path from root to p and store in n1
2. Similarrly find the path from root to q and store in n2
3. Compare the two paths and where they mismatches , stop there and return the last common path value
*/

/*Opimal one ,single travsersal
1. Recursively go to the left subtree and right subtree
2. Check if root->val==p or root->val==q , then return root
3. If left call gives null , then return right call value
4. If right call gives null then return left call value
5. Else return root value (i.e p and q find in left and right of root )
*/



class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root or root==p or root==q) return root;
        
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        
        if(!left){
            return right;
        }else if(!right){
            return left;
        }
        return root;
    }
};
