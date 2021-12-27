/* 
1.Take ans variable
2. If power is odd , decrement it by 1 and ans would be multiply by x
3. If power is even , multiply x by itself and decrement pow by 2;
4. Repeat it until power becomes 0
*/


class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long long t=n;
        if(t<0) t=abs(t);
        while(t){
            if(t&1){
                ans*=x;
                t-=1;
            }else{
                x*=x;
                t/=2;
            }
        }
        if(n<0) ans=(double)(1.0)/(double)(ans);
        return ans;
    }
};
