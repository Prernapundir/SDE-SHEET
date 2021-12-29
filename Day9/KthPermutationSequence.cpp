/*
1. Firstly one decrement k alue (considering o-based indexing)
2. Take a fact value at start till n
3. Store the numbers in array
4. Add numbers[k/fact] to ans , and reduce fact by numbers size , as we also have to erase the number from array
5. decrese k value also
*/


class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int> numbers;
        for(int i=1;i<n;i++){
            fact*=i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        k-=1;
        string ans;
        
        while(true){
           ans+=to_string(numbers[k/fact]);
           numbers.erase(numbers.begin()+k/fact);
           if(!numbers.size()) return ans;
           k%=fact;
           fact/=numbers.size();   
        }
        return ans;
    }
};
