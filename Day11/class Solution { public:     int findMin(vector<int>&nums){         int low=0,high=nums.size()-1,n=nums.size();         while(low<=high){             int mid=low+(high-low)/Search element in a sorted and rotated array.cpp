/*
1. Find the min element index using binary search
2. Then apply binary search over two sides
*/


class Solution {
public:
    int findMin(vector<int>&nums){
        int low=0,high=nums.size()-1,n=nums.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            int next=nums[(mid+1)%n];
            int prev=nums[(mid-1+n)%n];
            if(nums[mid]<=prev and nums[mid]<=next){
                return mid;
            }
            
            if(nums[mid]>=nums[0]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
    
    int BS(vector<int>&nums,int start,int end,int target){
        int low=start,high=end;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int min_index=findMin(nums);
        int left=BS(nums,0,min_index-1,target);
        int right=BS(nums,min_index,nums.size()-1,target);
        if(left!=-1) return left;
        else if(right!=-1) return right;
        return -1;
    }
};
