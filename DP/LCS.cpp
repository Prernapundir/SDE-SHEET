/*Approach
1. If s[i]==s[j]  reccur(i+1,j+1)
   else max(recur(i+1,j) || recur(j+1,i))
*/


class Solution {
public:
    
    int recur(int i,int j,string &s1,string &s2, vector<vector<int>>&dp){
        if(i>=s1.length() or j>=s2.length()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s2[j]){
            return dp[i][j]=recur(i+1,j+1,s1,s2,dp)+1;
        }
        return dp[i][j]=max(recur(i+1,j,s1,s2,dp),recur(i,j+1,s1,s2,dp));
    }
    
    int longestCommonSubsequence(string s1, string s2) {
        vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));
        return recur(0,0,s1,s2,dp);
    }
};
