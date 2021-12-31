

class Solution {
public:
    
    void nextSmallerRight(int n,vector<int>&heights,vector<int>&right){
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(st.size() and heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.size()) right[i]=-1;
            else right[i]=st.top();
            st.push(i);
         }
         return;    
    }
    
    void nextSmallerLeft(int n,vector<int>&heights,vector<int>&left){
        stack<int> st;
        for(int i=0;i<n;i++){
           while(st.size() and heights[st.top()]>=heights[i]){
               st.pop();
           }
           if(!st.size()) left[i]=-1;
           else left[i]=st.top();
           st.push(i);
        }
        return;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(),ans=0;
        vector<int>left(n),right(n);
        nextSmallerRight(n,heights,right);
        nextSmallerLeft(n,heights,left);
        
        
        for(int i=0;i<n;i++){
            int l = left[i];
            int r = right[i];
            int  w;
            if(r==-1) r = n;
            w = r-l-1;
            ans=max(w*heights[i],ans);
        }    
        return ans;
    }
};
