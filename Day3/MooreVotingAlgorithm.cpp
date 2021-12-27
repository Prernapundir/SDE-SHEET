/*Approach
1.Moore voting algorithm
2.Keep a count and store element  ,increment it if eccounters with the same element ,else decrement it.
3.Intutuion:- Minority elements will get canceled out by maority count

*/


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int element=0;
        
        for(auto i:nums){
            if(!count) element=i;
            if(element==i) count++;
            else count--;
        }
        return element;
    }
};
