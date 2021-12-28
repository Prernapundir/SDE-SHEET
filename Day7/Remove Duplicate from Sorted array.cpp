/*
Intuition: We can think of using two pointers ‘i’ and ‘j’,
we move ‘j’ till we don’t get a number arr[j] which is different from arr[i]. As we got a unique number we will increase the i pointer and update its value by arr[j]. 
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size()) return 0;
        int i=0,j=1;
        while(j!=nums.size()){
            if(nums[i]==nums[j]){
                j++;
            }else{
                nums[i+1]=nums[j];
                j++;
                i++;
            }
        }
        return i+1;
    }
};
