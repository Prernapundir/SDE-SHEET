

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxi=prices[0];
        int ans=0;
        
        for(int i=1;i<prices.size();i++){
            if(prices[i]<maxi){
                maxi=prices[i];
            }else{
                ans=max(ans,prices[i]-maxi);
            }
        }
        return ans;
    }
};
