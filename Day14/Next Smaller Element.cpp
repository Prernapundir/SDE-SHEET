/* variation of nge*/

vector<int> Solution::prevSmaller(vector<int> &arr) {
    int n=arr.size();
    vector<int> ans(n,-1);
    stack<int> st;
    

    for(int i=0;i<n;i++){
        while(!st.empty() and st.top()>=arr[i]){
            st.pop();
        }
        if(!st.empty() and st.top()<arr[i]){
            ans[i]=st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}
