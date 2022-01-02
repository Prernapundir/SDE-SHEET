
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> ans;
    
    void dfs(int src,vector<bool>&vis,vector<int>adj[]){
        vis[src]=1;
        ans.push_back(src);
        
        for(auto x:adj[src]){
            if(!vis[x]){
                dfs(x,vis,adj);
            }
        }
        return ;
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
            }
        }
        return ans;
    }
};
