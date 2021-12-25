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
       // Your code here
       vector<int> ans(n,1);
       stack<pair<int,int>>st;
       st.push({price[0],0});
       
       for(int i=1;i<n;i++){
           while(!st.empty() and st.top().first<=price[i]){
               st.pop();
           }
           if(!st.empty()){
               ans[i]=i-st.top().second;
           }else{
               ans[i]=i+1;
           }
           st.push({price[i],i});
       }
       
       return ans;
    }
};
