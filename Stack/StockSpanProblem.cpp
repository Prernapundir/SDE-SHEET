/*Approach
1. It's a stack problem
2. It's a vriation of nearest greater from left
3. In a stack store nearest graeter element
*/


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       
       vector<int> ans(n,1);
       stack<int>st;
    
       for(int i=0;i<n;i++){
           while(!st.empty() and price[st.top()]<=price[i]){
               st.pop();
           }
           if(!st.empty()){
               ans[i]=i-st.top();
           }else{
               ans[i]=i+1;
           }
           st.push(i);
       }
       
       return ans;
    }
};

