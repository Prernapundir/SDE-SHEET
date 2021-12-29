/*
1. Use binary search
2. Pair would exits as {even,odd}
3. if stand at odd index check for previous one
4. i stand at even index , check for next one }
*/


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
         if(nums.size()==1)
            return nums[0];
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid&1){
                // we are at odd index , so nums[mid] should be equal to nums[mid-1] as pair is {even,odd}
                if(nums[mid]==nums[mid-1]) low=mid+1;
                else high=mid-1;
            }else{
                // we are at even index , check or next index value , its should be same 
                if(nums[mid]==nums[mid+1]) low=mid+1;
                else high=mid-1;
            }
        }
        return nums[low];
    }
};
