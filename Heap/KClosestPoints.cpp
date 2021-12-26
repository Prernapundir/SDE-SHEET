/*Approach
1. Same like k smallest points , here also we have to make a max-heap
2. But here we hae to store a pair{diff, element}, we have to sort on the basis of difference betwwen x and element
3. Keep pushing pair until pq size becomes to k 
4. If size becomes greater than k , then pop
*/


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        
        for(int i=0;i<arr.size();i++){
            pq.push({abs(x-arr[i]),arr[i]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
