/*Approach
1. We have to maintain the inorder traversal , as we are not allowed to store the tree,
2. So maintain a stack in a constructor and initially push all the left elements into the stack
3. for next() -> take first element from the stack , and if its right exits then push all its left element
4. For hasnext()-> just check whether stack is empty or not

*/

class BSTIterator {
public:
    stack<TreeNode*> st;
    
    BSTIterator(TreeNode* root) {
        st.push(root);
        while(root->left){
            st.push(root->left);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode* top=st.top();
        st.pop();
        if(top->right){
            TreeNode* temp=top->right;
            st.push(temp);
            while(temp->left){
                st.push(temp->left);
                temp=temp->left;
            }
        }
        
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
