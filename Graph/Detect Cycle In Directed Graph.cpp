/*Dfs*/


class Solution {
public:

    bool check(int src,vector<int>adj[],vector<int>&vis,vector<int>&in_stack){
        vis[src]=true;
        in_stack[src]=true;
        
        for(auto x:adj[src]){
            if(!vis[x]){
                if(check(x,adj,vis,in_stack)) return true;
            }else {
                if(in_stack[x]){
                    return true;
                }
            }
        }
        
        in_stack[src]=false;
        
        return false;
    }
	bool isCyclic(int V, vector<int> adj[]) {
	   	vector<int> vis(V);
	   	vector<int> in_stack(V);
	   	
	   	
	   	for(int i=0;i<V;i++){
	   	    if(!vis[i]){
	   	        if(check(i,adj,vis,in_stack)) return true;
	   	    }
	   	}
	   	
	   	return false;
	}
};
