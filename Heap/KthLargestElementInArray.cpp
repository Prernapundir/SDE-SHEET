/*Approach
1. Take a min heap of size k
2. If size of heap less than k , push the element
3. If heap size is greater than k , pop top element and push only if element is greater than top 

/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int ,vector<int>,greater<int>> pq;
        
        for(int i=0;i<nums.size();i++){
            if(pq.size()<k) pq.push(nums[i]);
            else if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
                }
            }
        }
        return pq.top();
    }
};
