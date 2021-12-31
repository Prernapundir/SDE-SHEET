
class Solution
{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long > st;
        vector<long long> ans(n,-1);
        st.push(arr[n-1]);
        
        for(int i=n-2;i>=0;i--){
            while(!st.empty() and st.top()<=arr[i]){
                st.pop();
            }
            if(!st.empty() and st.top()>arr[i]){
                ans[i]=st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }
};
