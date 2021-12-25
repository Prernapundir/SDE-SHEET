/*Stack based Approach
1. First push the root node to the tree
2. Traverse till the stack will not be empty
3. Take top of stack and Push curr->right node first to the stack , then push curr->left node to the stack
4. Then make curr->right=st.top()
5. curr->left=NULL;
6. We are pushing right node first so that we can get left at the top of stack.
*/

class Solution {
public:
    
    void flatten(TreeNode* root) {
        if(!root) return;
        stack<TreeNode*>st;
        st.push(root);
        
        while(!st.empty()){
            cout<<"kk";
            TreeNode* curr=st.top();
            st.pop();
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
            if(!st.empty()){
               curr->right=st.top();
            }
            curr->left=NULL;
        }
        return;
    }
};

/*Recursive Approach
1. Take prev=NULL,Firsly flatten the right subtree
2. Then flatten the left subtree
3. Then root->right=root->left
   root->left=NULL;
   prev=root;
*/

class Solution {
public:
    TreeNode* prev=NULL;
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
        return ;
        
    }
};
