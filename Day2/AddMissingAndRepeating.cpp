/*Negative making Aprrocah

*/



class Solution{
public:
    int *findTwoElement(int *A, int n) {
        // code here
        int repeat,missing;


    for(int i=0;i<n;i++){
        int val=A[abs(A[i])-1];
        if(val<0){
            repeat=abs(A[i]);
  
        }else{
            A[abs(A[i])-1]*=-1;
        }
        
    }

    for(int i=0;i<n;i++){
        if(A[i]>0){
            missing=i+1;
            break;
        }
    }
    int *ans=new int[2];
    ans[0]=repeat;
    ans[1]=missing;
    return ans;
    }
};
