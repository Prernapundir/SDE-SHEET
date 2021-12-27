/*Merge sort technique*/


class Solution{
  public:

    long long  merge(long long arr[], long long low,long long high,long long mid){
        long long count=0;
        long long int  temp[(high-low+1)];
        long long int i=low, j=mid,k=0;
        
        while(i<mid and j<=high){
            if(arr[i]>arr[j]){
                count+=(mid-i);
                temp[k]=arr[j];
                j++;
            }else{
                temp[k]=arr[i];
                i++;
            }
            k++;
        }
        
        while(i<mid){
            temp[k]=arr[i];
            k++;
            i++;
        }
        
        while(j<=high){
            temp[k]=arr[j];
            k++;
            j++;
        }
        
        for(long long i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
        return count;
    }
    
    long long mergeSort(long long arr[], long long low,long long high){
        long long  count=0;
       if(high>low){
           long long mid=low+(high-low)/2;
           count+=mergeSort(arr,low,mid);
           count+=mergeSort(arr,mid+1,high);
           count+=merge(arr,low,high,mid+1);
       }
       return count;
    }
    long long int inversionCount(long long arr[], long long N)
    {
   
       return mergeSort(arr,0,N-1);

    }

};



