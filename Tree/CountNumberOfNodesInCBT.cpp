// Complete Binary Tree(CBT) = A tree who is completely filled till the last 2nd level and whose last level is filled from left to right.
// Nodes in a CBT=PBT , 2^h-1
// Use this property and find the numbres of nodes in less than O(n) time complexity.

/*Approach
-->BruteForce
1. Use any traversal method and time complexity would be O(n)
--> Optimal Approach
1. Number of nodes in a CBT = 2^h - 1 (where h=height of tree)
2. Trverse from root and find left height(lh) and right height(rh).
3. If (rh==lh) nodes= 2^lh-1;
   else 1+ leftcall() + rightcall;
4. Time complexity would be O(logn)^2= O(logn) for traversing nodes + O(logn) for calculating lh ,rh
*/


class Solution {
public:
    int countNodes(TreeNode* root) {
      if(!root) return 0;
        int lh=0,rh=0;
        TreeNode* temp=root;
        while(temp){
            lh++;
            temp=temp->left;
        }
        temp=root;
        while(temp){
            rh++;
            temp=temp->right;
        }
        if(lh==rh) return pow(2,lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
