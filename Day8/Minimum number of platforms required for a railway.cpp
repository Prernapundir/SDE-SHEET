/*
Intuition: At first we need to sort both the arrays. When the events will be sorted, it will be easy to track the count of trains that have arrived but not departed yet. 
Total platforms needed at one time can be found by taking the difference of arrivals and departures at that time and the maximum value of all times will be the final answer.
*/


class Solution
{
    public:

    static bool compare(pair<int,int>a ,pair<int,int>b){
        return b.second>a.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++){
            a[i].first=start[i];
            a[i].second=end[i];
        }
        sort(a.begin(),a.end(),compare);
        int count=1;
        pair<int,int> p=a[0];
        for(int i=1;i<n;i++){
            if(a[i].first>p.second){
                count++;
                p=a[i];
            }
        }
        return count;
    }
};
