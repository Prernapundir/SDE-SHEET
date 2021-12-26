/*Negative making approach
*/



class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;
       for(int i=0;i<nums.size();i++){
           int val=nums[abs(nums[i])-1];
           if(val<0){
               ans=abs(nums[i]);
           }
           nums[abs(nums[i])-1]*=-1;
       }
        return ans;
    }
};


/*Tortoise method*/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(fast!=slow);
        
        slow=nums[0];
        
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
        
    }
};
