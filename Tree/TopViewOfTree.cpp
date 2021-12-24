/*Approach
1.We will make a queue and store {root,level} 
2.And also a map which will store {root->val,level}
3. Take queue's front value , if it's present in map , just pop it ,else push it to the map(i.e it's visited first time }
4. Trverse the map and get the top view 
5. Time complexity and space complexity = O(n)
6. Can we use recursive approach directly = NO
*/

 vector<int> topView(Node *root)
    {
        queue<pair<Node*,int>> q;
        map<int ,int> mp;
        q.push({root,0});
        
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            Node* node=f.first;

            int line=f.second;
            if(mp.find(line)==mp.end()) mp[line]=node->data;
            if(node->left) q.push({node->left,line-1});
            if(node->right) q.push({node->right,line+1});
        }
        
        vector<int> ans;
        for(auto i: mp){

            ans.push_back(i.second);
        }
        return ans;
    }
