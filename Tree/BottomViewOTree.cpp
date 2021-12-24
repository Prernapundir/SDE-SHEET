/*Approach
1. Same like top view
2. We have to maintain a queue of {root,level} and a map of {root->val,level}
3. This time we have to print the last value of every level {opposite in case of top view}
*/

   vector <int> bottomView(Node *root) {
        map<int,int> m;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        m[0]=root->data;
        
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            m[f.second]=(f.first)->data;
            if((f.first)->left) q.push({(f.first)->left,(f.second)-1});
            if((f.first)->right) q.push({(f.first)->right,(f.second)+1});
        }
        
        vector<int> ans;
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
