/*
1.Sort on the basis of finishing time 
*/


class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool compare(pair<int,int>a ,pair<int,int>b){
        return b.second>a.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
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
