

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count=0,count=0;
        for(auto i:nums){
            if(i==1) count++;
            else{
                max_count=max(max_count,count);
                count=0;
            }
        }
        max_count=max(count,max_count);
        return max_count;
    }
};
