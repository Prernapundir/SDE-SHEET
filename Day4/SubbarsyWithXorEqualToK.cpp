/*Approach
1. We will store all the visisted xors with count in a map.
2. As y^k=xr === y=k^xr 
3. So for every xr , we will calculate y and will search in map , if found , thne increnement the ans with frequenecy count of that xor
*/

int Solution::solve(vector<int> &A, int k) {

    unordered_map<int,int> m;
    int count=0; 

    int xr=0;

    for(int i=0;i<A.size();i++){
        xr=xr^A[i];
        int y=xr^k;
        if(xr==k) count++;
        if(m.find(y)!=m.end()){
            count+=m[y];
        }
        m[xr]++;
    }
    return count;
}
