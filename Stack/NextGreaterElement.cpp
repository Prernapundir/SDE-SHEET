/*Approach
1. Start from the last of the arr
2. If curr element is greater than the top of stack , pop the stack element
   Else mark it curr nge.
3. Keep pushing to the stack.
*/



class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
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
