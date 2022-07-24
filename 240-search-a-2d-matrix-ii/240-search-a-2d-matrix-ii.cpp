class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS= matrix.size();
        int COLS = matrix[0].size();
        int r =0;
        int c = COLS-1;
        while(r<ROWS && c>=0){
            if(matrix[r][c]==target) return true;
            if(matrix[r][c]>target) c--;
            else  r++;
        }
        return false;
    }
};