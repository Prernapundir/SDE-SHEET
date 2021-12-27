/*
1.Take a hashmap, and store all the values
2. For every value Check for previous consecutive value in map , if exists, no need to check for the value
3. If not exists, count the consecutives for this one 
*/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i:nums){
            mp[i]++;
        }
        int count=0;
        
        for(auto i: nums){
            if(mp.find(i-1)!=mp.end()) continue;
            int temp=0;
            int val=i;
            while(mp.find(val)!=mp.end()){
                temp++;
                val++;
            }
            count=max(temp,count);
        }
        return count;
        
    }
};
