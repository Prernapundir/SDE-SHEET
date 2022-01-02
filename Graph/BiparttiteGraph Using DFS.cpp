


class Solution {
public:
    
    bool dfs(int src,vector<int>&color,vector<bool>&vis,vector<vector<int>>&graph,int parent){
        color[src]=-parent;
        vis[src]=1;
        for(auto x:graph[src]){
            if(!vis[x]){
                if(!dfs(x,color,vis,graph,-parent)) return false;
            }else if(color[x]==color[src]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,0);
        vector<bool> vis(n);
        for(int i=0;i<n;i++){
            if(!vis[i] and !dfs(i,color,vis,graph,1)) return false;
        }
        return true;
    }
};
