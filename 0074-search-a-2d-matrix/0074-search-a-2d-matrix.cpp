class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols =matrix[0].size();


        int lo =0;
        int high=rows*cols-1;

        while(lo<=high){
            int mid=lo+(high-lo)/2;

            int row =mid/cols;
            int col= mid%cols;

            if(matrix[row][col] == target)  return true;

            if(matrix[row][col] <target) lo =mid+1;



            else high  = mid -1;

        }
        return false;
    }
};