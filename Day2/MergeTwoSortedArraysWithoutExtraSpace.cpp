


 void merge(long long arr1[], long long arr2[], int n, int m) 
 {   
        long long i=0,j=0,k;
        for(i=0;i<n;i++){
            if(arr1[i]>=arr2[0]){
               swap(arr1[i],arr2[0]);
            }
            long long temp=arr2[0];
            for(k=1;k<m and temp>arr2[k];k++){
                arr2[k-1]=arr2[k];
            }
            arr2[k-1]=temp;
         }
} 
