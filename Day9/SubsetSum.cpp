/*Either include or exclude approach */



class Solution
{
public:
    
    void recur(vector<int>&arr,vector<int>&ans,int n,int sum,int i){
        if(i>=n){
            ans.push_back(sum);
            return;
        }
        recur(arr,ans,n,sum,i+1);
        sum+=arr[i];
        recur(arr,ans,n,sum,i+1);
        return;
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        recur(arr,ans,N,0,0);
        return ans;
    }
};
