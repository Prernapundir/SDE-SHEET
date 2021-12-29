/*
Sort the jobs in descending order of profit. 
If the maximum deadline is x, make an array of size x .Each array index is set to -1 initially as no jobs have been performed yet.
For every job check if it can be performed on its last day.
If possible mark that index with the job id and add the profit to our answer. 
If not possible, loop through the previous indexes until an empty slot is found.
*/


struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool compare(Job a,Job b){
        return a.profit>b.profit;
    }
    int jobs=0,profit=0;
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int> ans,dp(n,-1);
        sort(arr,arr+n,compare);
        for(auto x=0;x<n;x++){
            int deadline=arr[x].dead;
            
            for(int i=deadline-1;i>=0;i--){
                if(dp[i]==-1){
                    jobs++;
                    profit+=arr[x].profit;
                    dp[i]=0;
                    break;
                }
            }
        }
        ans.push_back(jobs);
        ans.push_back(profit);
        return ans;
        
    } 
};
