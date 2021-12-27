/*
1. Used unordered_map to store the value ,do one pass
2.We can solve this problem efficiently by using hashing.
We’ll use a hash-map to see if there’s a value target – i that can be added to the current array value i to get the sum equals to target. 
If target – i is found in the map, we return the current index, and index stored at target – nums[index] location in the map. 
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> ans;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            int val=target-nums[i];
            if(m.find(val)!=m.end()){
                ans.push_back(m[val]);
                ans.push_back(i);
                break;
            }
            m[nums[i]]=i;
        }
        return ans;
    }
};
