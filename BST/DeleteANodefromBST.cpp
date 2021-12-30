

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val>key){
            root->left=deleteNode(root->left,key);
        }else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }else{
            if(!root->left and !root->right) {
                delete root;
                return NULL;
            }else if(!root->left or !root->right){
                TreeNode* temp=root->left?root->left:root->right;
                delete(root);
                return temp;
            }else{
                TreeNode* temp=root->right;
                while(temp->left){
                    temp=temp->left;
                }
                root->val=temp->val;
                root->right=deleteNode(root->right,temp->val);
                return root;
            }
        }
        return root;
    }
};
