/*Topological Sort using DFS */



class Solution
{
	public:
	
	void dfsTopo(int src,vector<bool>&vis,stack<int>&st,vector<int>adj[]){
	    vis[src]=1;
	    for(auto x:adj[src]){
	        if(!vis[x]){
	          dfsTopo(x,vis,st,adj);
	        }
	    }
	    st.push(src);
	    return;
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{

	    vector<bool>vis(V);
	    vector<int>ans;
	    stack<int>st;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfsTopo(i,vis,st,adj);
	        }
	    }
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};



/*Using BFS*/

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0),ans;
	    for(int i=0;i<V;i++){
	        for(auto x:adj[i]){
	            indegree[x]++;
	        }
	    }
	    queue<int> q;
	    
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int f=q.front();
	        ans.push_back(f);
	        q.pop();
	        
	        for(auto x:adj[f]){
	           indegree[x]--;
	           if(indegree[x]==0){
	               q.push(x);
	           }
	        }
	    }
	    return ans;
	}
};





