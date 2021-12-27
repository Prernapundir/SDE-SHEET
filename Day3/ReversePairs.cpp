/*
1.Merge Sort technique used.
2. In the Merge function, we will be using low, mid, high values to count the total number of inversion pairs for the Left half and Right half of the Array.
*/



class Solution {
public:
    
    int count=0;
    
    void merge(vector<int>&nums,int l,int h,int mid){
        int i=l,j=mid+1;
        while(i<=mid){
            while(j<=h && nums[j]*2LL<nums[i]){
                j++;
            }
            count+=j-(mid+1);
            i++;
        }
        
        i=l,j=mid+1;
        vector<int> temp;
        
        while(i<=mid and j<=h){
            if(nums[i]>nums[j]){
                temp.push_back(nums[j]);
                j++;
            }else{
                temp.push_back(nums[i]);
                i++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=h){
            temp.push_back(nums[j]);
            j++;
        }
        
        for(i=l;i<=h;i++){
            nums[i]=temp[i-l];
        }
        return;
    }
    
    void mergeSort(vector<int>&nums,int l,int h){
        if(l>=h) return ;
        int mid=l+(h-l)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,h);
        merge(nums,l,h,mid);
        return;
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return count;
    }
};
