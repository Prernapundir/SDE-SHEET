/*BFS*/


class Solution {
public:

  
    bool check(vector<int>&vis,int src,vector<int>adj[],int V){
        vector<int> parent(V);
	    queue<int> q;
	    q.push(src);
	    parent[src]=src;
	    vis[src]=true;
	    
	    while(!q.empty()){
	        int f=q.front();
	        q.pop();
	        
	        
	        for(auto x:adj[f]){
	            if(vis[x] and parent[f]!=x){
	                return true;
	            }else{
	                if(!vis[x]){
	                    vis[x]=true;
	                    parent[x]=f;
	                    q.push(x);
	                }
	            }
	        }
	    }
	    return false;
    }
    
    
	bool isCycle(int V, vector<int>adj[]){
	     vector<int> vis(V,false);
	     
	     for(int i=0;i<V;i++){
	         if(!vis[i] and check(vis,i,adj,V)){
	             return true;
	         }
	     }
	    
	    return false;
	}
};



/*DFS*/
class Solution {
public:


    bool dfs(int src,vector<int>adj[],vector<bool>&vis,int parent){
        vis[src]=1;
        for(auto x:adj[src]){
            if(!vis[x] ){
                if(dfs(x,adj,vis,src)) return true;
            }else if(x!=parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>vis(V);
        for(int i=0;i<V;i++){
            if(!vis[i] and dfs(i,adj,vis,-1)){
                return true;
            }
        }
       
        return false;
    }
};


