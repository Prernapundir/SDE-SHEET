/*
1. Do the binary search , and find count of smaller elements for every mid value.
2. For a  medain it;s pretty sure , count of smaller elements and greater would be n/2
3. For counting smaller elements , do the  binary search
*/


int countSmallerThanMid(vector<int>&row,int val){
    int low=0,high=row.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(row[mid]<=val){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return low;
}

int Solution::findMedian(vector<vector<int> > &A) {
   int low=0,high=1e9;
   int n=A.size();
   int m=A[0].size();
   while(low<=high){
     int mid=low+(high-low)/2;
     int count=0;
     for(int i=0;i<n;i++){
         count+=countSmallerThanMid(A[i],mid);
     }

     if(count<=(n*m)/2){
         low=mid+1;
     }else{
         high=mid-1;
     }
   }

   return low;
    
}
