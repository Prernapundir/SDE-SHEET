
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> ans;
    void bfs(int src,vector<bool>&vis,vector<int>adj[]){
        queue<int> q;
        q.push(src);
        vis[src]=1;
        
        while(!q.empty()){
            int f=q.front();
            q.pop();
            ans.push_back(f);
            
            for(auto x:adj[f]){
                if(!vis[x]){
                    q.push(x);
                    vis[x]=1;
                }
            }
        }
        return;
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
          vector<bool>vis(V);
        //   for(int i=0;i<V;i++){
            //   if(!vis[i]){
                  bfs(0,vis,adj);
            //   }
        //   }
       
       return ans;
    }
};

