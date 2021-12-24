/*Approach
1. Take pstart, isart,iend and take pstart as global variable.
2. Pick one element from preorder at every time and then search in inorder array
3. After searching you will get the index of element and just do the recursive call
4. From (istart to index-1) and (index+1 to iend) and build the tree
5. {it will generate the unique binary tree}
*/

class Solution {
public:
    int pstart=0;
  
    TreeNode* recur(vector<int>&pre, vector<int>& in,int istart,int iend){
        if(istart>iend) return NULL;
        TreeNode* root=new TreeNode(pre[pstart++]);
        
        int index=0;
        
        for(int i=istart;i<=iend;i++){
            if(in[i]==root->val){
                index=i;
                break;
            }
        }
      
        root->left=recur(pre,in,istart,index-1);
      
        root->right=recur(pre,in,index+1,iend);
      
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        return recur(pre,in,0,in.size()-1);
    }
};
