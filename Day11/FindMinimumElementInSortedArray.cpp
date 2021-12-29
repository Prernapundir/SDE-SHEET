/*
Simple check with high ,
if mid>high , go to right side
else if mid<high fo to left side
else hugh-- //for duplicates

*/


class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,n=nums.size();
        int high=nums.size()-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            int next=nums[(mid+1)%n];
            int prev=nums[(mid-1+n)%n];
            if(prev>=nums[mid] and next>=nums[mid]){
                return nums[mid];
            }
                         
            if(nums[mid]>=nums[high]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return nums[low];
                         
    }
};
