class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        //int n stores the number of rows of the matrix
        int n = matrix.size();
        //m stores the number of columns of the matrix
        int m = matrix[0].size();
        //sol stores the final transpose matrix
        vector<vector<int>> sol(m,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // basic transpose logix aij=aji
                sol[j][i] = matrix[i][j];
            }
        }
        //return the ans
        return sol;
    }
};