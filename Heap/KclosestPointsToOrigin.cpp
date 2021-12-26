/*Approach
1. Here we have to store the diff between two points along with the pair{x,y}
2. Make a min heap
*/


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<int>>ans;
        
        for(auto i:points){
            int dis=(i[0]*i[0])+(i[1]*i[1]);
            pq.push({dis,{i[0],i[1]}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>temp(2);
        while(!pq.empty()){
            temp[0]=(pq.top().second).first;
            temp[1]=(pq.top().second).second;
            ans.push_back(temp);
            pq.pop();
        }
        return ans;
    }
};
