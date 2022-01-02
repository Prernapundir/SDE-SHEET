

class Solution {
public:
    int height(TreeNode* root,int &diameter){
        if(!root) return 0;
        int left=height(root->left,diameter);
        int right=height(root->right,diameter);
        diameter=max(diameter,left+right);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
};
