/*
Avoid duplicates in this approach , for loop will take care of that*/


class Solution {
public:
    vector<vector<int>>ans;
    void recur(int start,int n,vector<int>&nums,vector<int>&temp){
        ans.push_back(temp);
        for(int i=start;i<n;i++){
            if(i!=start and nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            recur(i+1,n,nums,temp);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        recur(0,nums.size(),nums,temp);
        return ans;
    }
};
