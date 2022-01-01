/*Approach
1. Unbounded knapsack problem

*/

class Solution {
public:
     int recur(vector<int>&coins,int amount,int i, vector<vector<int>>&dp){
         if(amount<0 || i>=coins.size()) return INT_MAX-1;

         if(amount==0) return 0;
         
         if(dp[i][amount]!=-1) return dp[i][amount];
         int op1;
         
         if(coins[i]<=amount){
            op1=min(1+recur(coins,amount-coins[i],i,dp),recur(coins,amount,i+1,dp));
         }else{
            op1=recur(coins,amount,i+1,dp);
         }
         return dp[i][amount]=op1;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int res=recur(coins,amount,0,dp);
        return res==INT_MAX-1?-1:res;
    }
};
