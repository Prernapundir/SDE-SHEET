/*Approch 
1. Without using additional space, we can use matrix first row and first column to store 0 value
2. As matrix[0][0] is common for both first row and first column , so for that use the col variable.
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        bool col=false;
        
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0) col=true;
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=1;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
            if(col){
                matrix[i][0]=0;
            }
        }
        return;
    }
};
