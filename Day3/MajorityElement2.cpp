/*Approach
num1 and num2 will store our currently most frequent and second most frequent element.
c1 and c2 will store their frequency relatively to other numbers.
We are sure that there will be a max of 2 elements which occurs > N/3 times because there cannot be if you do a simple math addition.
Let, ele be the element present in the array at any index. 

if ele == num1, so we increment c1.
if ele == num2, so we increment c2.
if c1 is 0, so we assign num1 = ele.
if c2 is 0, so we assign num2 = ele.
In all the other cases we decrease both c1 and c2.

*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count1=0;
        int count2=0;
        int element1=-1;
        int element2=-1;
        
        for(auto i: nums){
            if(element1==i) count1++;
            else if(element2==i) count2++;
            else if(count1==0){
                element1=i;
                count1=1;
            }else if(count2==0){
                element2=i;
                count2=1;
            }else{
                count1--;
                count2--;
            }
        }
        int c1=0,c2=0;
        for(auto i:nums){
            if(i==element1) c1++;
            else if(i==element2) c2++;
        }
        
        vector<int> ans;
        if(c1>n/3) ans.push_back(element1);
        if(c2>n/3) ans.push_back(element2);
        return ans;
    }
};
