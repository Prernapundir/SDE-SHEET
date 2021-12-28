/*
1.Calucualer prefix leftmax and rightmax for every index
2.Then ans would be min(left[i],right[i])-arr[i] at any index
*/



class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size(),ans=0;
        vector<int>left(n,0),right(n,0);
        int leftmax=0,rightmax=0;
        
        for(int i=0;i<n;i++){
            if(leftmax>=arr[i]){
                left[i]=leftmax;
            };
            leftmax=max(leftmax,arr[i]);

        }
        
        for(int i=n-1;i>=0;i--){
            if(rightmax>=arr[i]){
                right[i]=rightmax;
            }
            rightmax=max(rightmax,arr[i]);
        }
        
        
        for(int i=0;i<n;i++){
            int val=min(left[i],right[i]);
            if(val>=arr[i]){
                ans+=min(left[i],right[i])-arr[i];
            }
        }
        return ans;
        
    }
};
