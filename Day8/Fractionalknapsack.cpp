/*
Since it is possible to break the items as well we should focus on picking up items having higher value /weight first.
To achieve this, items should be sorted in decreasing order with respect to their value /weight. Once the items are sorted we can iterate. 

*/

struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(Item a,Item b){
        double r1=(double)a.value/(double)a.weight;
        double r2=(double)b.value/(double)b.weight;
        return r1>r2;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,cmp);
        double profit=0;
        int curr_weight=0;
        
        for(int i=0;i<n;i++){
            if(curr_weight+arr[i].weight<=W){
                profit+=arr[i].value;
                curr_weight+=arr[i].weight;
            }else{
                int remain=W-curr_weight;
                profit+=arr[i].value*(double)remain/(double)arr[i].weight;
                break;
            }
        }
        return profit;
    }
        
