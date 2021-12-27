/*Approach
1.Start from top right corner and check whether the value is smaller or greater
2. On that basis increment row or column 
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0,j=n-1;
        
        while(i<m and j>=0){
            if(matrix[i][j]>target){
                j--;
            }else if(matrix[i][j]<target){
                i++;
            }else{
                return true;
            }
        }
        return false;
    }
};



/*Binary Search Method
*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int s=0,e=m*n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int val=matrix[mid/n][mid%n];
            if(val>target){
                e=mid-1;
            }else if(val<target){
                s=mid+1;
            }else return true;
        }
        return false;
    }
};
