/*
Approach: 

First let us initialise a variable say sum = 0 which stores the sum of elements traversed so far and another variable say max = 0 which stores the length of longest subarray with sum zero.
Declare a HashMap<Integer, Integer> which stores the prefix sum of every element as key and its index as value.
Now traverse the array, and add the array element to our sum. 
 (i)  If sum = 0, then we can say that the subarray until the current index has a sum = 0,      so we update max with the maximum value of (max, current_index+1)

(ii)  If sum is not equal to zero then we check hashmap if we’ve seen a subarray with this sum before

if HashMap contains sum -> this is where the above-discussed case occurs (subarray with equal sum), so we update our max 

else -> Insert (sum, current_index) into hashmap to store prefix sum until current index

After traversing the entire array our max variable has the length of longest substring having sum equal to zero, so return max.


*/


class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        
        for(int i=0;i<A.size();i++){
            sum+=A[i];
            if(sum==0){
                ans=i+1;
            }else{
                if(mp.find(sum)!=mp.end()){
                  ans=max(ans,i-mp[sum]);
                 }else{
                mp[sum]=i;
               }
         }
            
        }
        
        return ans;
    }
};
