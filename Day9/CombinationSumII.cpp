

class Solution {
public:
    
    vector<vector<int>>ans;
    
    void recur(int start,vector<int>temp,vector<int>&candidates,int target){
        
        if(target==0){
            ans.push_back(temp);
            return;
        }
        
        if(start>=candidates.size() || target<0) return;
        
        for(int i=start;i<candidates.size();i++){ // to avoid duplicate elements
            if(i!=start and candidates[i]==candidates[i-1]) continue;
            temp.push_back(candidates[i]); //firstly including the candidate
            recur(i+1,temp,candidates,target-candidates[i]);
            temp.pop_back(); //excluding the candidate
        }
        
        return;
        
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        recur(0,temp,candidates,target);
        return ans;
    }
};
