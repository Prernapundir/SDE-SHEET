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



/*BFS using Topological Sort [Kahn's Algorithm}
==> If able to generate topological sort , then cycle not present , else present

*/


class Solution {
public:
    
    
    bool canFinish(int n, vector<vector<int>>& a) {
        
        vector<int> adj[n];
        for(auto i:a){
           adj[i[0]].push_back(i[1]); 
        }
        
        queue<int> q;
        vector<bool> vis(n);
        int count=0;
        vector<int> indegree(n,0);
        
        for(int i=0;i<n;i++){
            for(auto x:adj[i]){
                indegree[x]++;
            }
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int f=q.front();
            q.pop();
            count++;
            
            for(auto x:adj[f]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
        if(count==n) return true;
        return false;
        
    }
};



