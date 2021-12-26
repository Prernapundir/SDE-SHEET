/*Approach
1. Find the index till when a[i]<a[i+1]=index1
2. Find the index till when a[i]>a[index1]=index2
3.Swap index1,index2
4. Reverse from index+1 till the end of array
*/



class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int index;
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]>nums[i]){
                index=i;
                break;
            }
        }
        
        if(index<0){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        int num_index;
        
        for(int i=n-1; i>index;i--){
            if(nums[i]>nums[index]){
                num_index=i;
                break;
            }
        }
        
        swap(nums[index],nums[num_index]);
        reverse(nums.begin()+index+1,nums.end());
        return;
    }
};
