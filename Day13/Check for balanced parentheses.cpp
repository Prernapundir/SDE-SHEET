class Solution {
public:
    bool isValid(string s) {
        int i=0;
        stack<char> st;
        
        while(i<s.size()){
            if(s[i]=='(' or s[i]=='{' or s[i]=='['){
                st.push(s[i]);
            }else if(!st.empty() and s[i]==')' and st.top()=='('){
                st.pop();
            }else if(!st.empty() and s[i]=='}' and st.top()=='{'){
                st.pop();
            }else if(!st.empty() and s[i]==']' and st.top()=='['){
                st.pop();
            }else{
                return false;
            }
            i++;
        }
        return st.size()==0 and i>=s.size();
    }
};
