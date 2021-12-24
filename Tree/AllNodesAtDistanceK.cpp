/*Approach
--> We can start normal BFS from the target , but the thing is how we can go backward
--> Fo going towards root(backward) from child node , we can do one thing we can store the parent node
--> Then do the normal bfs and keep track the distance levels we covered till so far
1. First do the bfs , find parent node of every node and store them
2. Now run the bfs again from target node in all three direction and also add the visited nodes in a visited map
3. Keep a track of levels using a variable dis=0, increment it after every iteration.
4. Stop the bfs when (dis==k) and then the nodes present in the queue will be the nodes at distance k from target node.
*/
class Solution {
public:
    
    void find_parent(TreeNode*root, unordered_map<TreeNode*,TreeNode*>& m){
        queue<TreeNode*> q;
        q.push(root);
        m[root]=root;
        while(!q.empty()){
            TreeNode* f=q.front();
            q.pop();
            if(f->left) {
                q.push(f->left);
                m[f->left]=f;
            }
            if(f->right){
                q.push(f->right);
                m[f->right]=f;
            }
        }
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        find_parent(root,parent);
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*,bool> vis;
        vis[target]=true;
        int dis=0;
        
        while(!q.empty()){
            int size=q.size();
            
            if(dis==k){
                for(int i=0;i<size;i++){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                break;
            }
            for(int i=0;i<size;i++){
                TreeNode* f=q.front();
                TreeNode* p=parent[f];
                if(f->left and vis.find(f->left)==vis.end()){
                    q.push(f->left);
                    vis[f->left]=true;
                }
                if(f->right and vis.find(f->right)==vis.end()){
                    q.push(f->right);
                    vis[f->right]=true;
                }
                if(!vis[p]){
                    q.push(p);
                    vis[p]=true;
                }
                q.pop();
            }
            dis++;
        }
        return ans;
    }
};
