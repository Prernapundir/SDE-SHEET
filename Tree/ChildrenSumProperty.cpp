/*Approach
1. Used Dfs 
2. Store left and right node value into varibale val
3. If root value is greater , then just change root->left and root->right value with the val
4. If root is less then change root->val with the val
5. After the bactrack again chcek for left and right val and then change the root->val
6. Time Complexity = O(n)
*/



void changeTree(BinaryTreeNode < int > * root) {
    if(!root) return;
    int val=0;
    if(root->left) val+=root->left->data;
    if(root->right) val+=root->right->data;
    if(val>=root->data) root->data=val;
    else{
        if(root->left) root->left->data=root->data;
        if(root->right) root->right->data=root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    
     val=0;
    if(root->left) val+=root->left->data;
    if(root->right) val+=root->right->data;
    if(root->left or root->right) root->data=val;
}  
