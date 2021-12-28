/*
1.O(n^2) approach
2. Two Sum + two pointer
3. Basically extended version of 3 sum
*/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4) return {};
        
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 and nums[j]==nums[j-1]) continue;
                int l=j+1,m=n-1;
                int sum=target-(nums[i]+nums[j]);
                while(l<m){
                    int val=nums[l]+nums[m];
                    if(val>sum){
                        m--;
                    }else if(val<sum){
                        l++;
                    }else{
                        temp.clear();
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[m]);
                        ans.push_back(temp);
                        while(l<m and nums[l]==nums[l+1]) l++;
                        while(l<m and nums[m]==nums[m-1]) m--;
                        l++;
                        m--;
                    }
                }
            }
        }
        return ans;
    }
};
