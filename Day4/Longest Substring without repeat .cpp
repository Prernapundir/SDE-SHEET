
/*
1. Store the element if encounter before 
2. If encounter beore , don't include it 

*/



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int> m;
        
        int i=0,j=0;
        int ans=0;
        
        while(j<s.size()){
            if(m.find(s[j])!=m.end()){
                i=max(m[s[j]]+1,i);
            }
            ans=max(ans,j-i+1);
            m[s[j]]=j;
            j++;
        }
        
        return ans;
    }
};
