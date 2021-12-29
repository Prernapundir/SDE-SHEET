/* Partition at every index and then check , is it a palindrome or not */



class Solution {
public:
    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    
    vector<vector<string>>ans;
    
    void recur(string s, int start,vector<string> &temp){
        if(start==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=start;i<s.length();i++){
            if(isPalindrome(s,start,i)){
                temp.push_back(s.substr(start,i-start+1));
                recur(s,i+1,temp);
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        recur(s,0,temp);
        return ans;
    }
};
