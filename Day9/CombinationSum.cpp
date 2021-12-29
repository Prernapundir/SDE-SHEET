/*
Take care of one thing ,same value can be added agai target, add it till the target become less the value */

class Solution {
public:
    vector<vector<int>> ans;
    
    void recur(int i,vector<int>temp,int target,vector<int>& candidates){
       if(target==0){
           ans.push_back(temp);
           return;
       }
       if(target<0 || i>=candidates.size()) return;
       recur(i+1,temp,target,candidates); // If not included the current index, target would remain same
      
       if(candidates[i]<=target){
           temp.push_back(candidates[i]); // If included the current index, target would decrease by index value 
           target-=candidates[i];
           recur(i,temp,target,candidates);
       }
       return;
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        recur(0,temp,target,candidates);
        return ans;
    }
};
