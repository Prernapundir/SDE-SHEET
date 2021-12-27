/*Approach
1. Recursively we will go either rightward and downward
2. Will try all thr possible solutions

*/


class Solution {
public:
    
    int recur(int x,int y,int m,int n, vector<vector<int>>&dp){
        if(x==m-1 && y==n-1) return dp[x][y]=1;
        
        if(x>=m || y>=n) return 0;
        
        if(dp[x][y]!=-1) return dp[x][y];
        
        int op1=recur(x+1,y,m,n,dp);
        int op2=recur(x,y+1,m,n,dp);
        
        return dp[x][y]=op1+op2;
    }
    
    int uniquePaths(int m, int n) {
       vector<vector<int>>dp(m,vector<int>(n,-1));
       recur(0,0,m,n,dp) ;
       return dp[0][0];
    }
};
