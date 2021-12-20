/*Approach
1. We have to find the horizontal distance(hd) and vertical distance(vd) of each node
2. Start from root node
3. Maintain a map where key would be (vd) and store pair{hd,node->val) in a vector as: {map<int,vector<pair<int,int>>>}
4. Go to the left subtree and make hd=hd+1 and vd=vd-1
5. Similarly for right subtree make hd=hd+1 and vd=vd+1
6. At the end traverse the map and extract the order.
*/



class Solution {
public:
    
    void dfs(int hd,int vd,TreeNode* root,map<int,vector<pair<int,int>>>&m)
    {
        if(!root) return;
        m[vd].push_back({hd,root->val});
        dfs(hd+1,vd-1,root->left,m);
        dfs(hd+1,vd+1,root->right,m);
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> m;
        dfs(0,0,root,m);
        
        vector<vector<int>>ans;
        for(auto i:m){
            sort(i.second.begin(),i.second.end());
            vector<int>temp;
            for(auto x:i.second){
                temp.push_back(x.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
