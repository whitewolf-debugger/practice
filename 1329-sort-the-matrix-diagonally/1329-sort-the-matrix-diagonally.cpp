class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int ROWS = mat.size();
        int COLS = mat[0].size();
        vector<int> diagonal;
         
        for(int r = 0; r < ROWS; r++){
            
            diagonal.clear();
            
            for(int row = r, col = 0; row < ROWS && col < COLS; row++,col++){
                diagonal.push_back(mat[row][col]);
            }
            
            sort(diagonal.begin() , diagonal.end());
            
            int k =0;
            for(int row = r, col = 0; row < ROWS && col < COLS; row++,col++){
                mat[row][col] = diagonal[k++];
            }
            
        }
        
        for(int c = 0; c < COLS; c++){
            
            diagonal.clear();
            
            for(int row = 0, col = c; row < ROWS && col < COLS; row++,col++){
                diagonal.push_back(mat[row][col]);
            }
            
            sort(diagonal.begin() , diagonal.end());
            
            int k =0;
            for(int row = 0, col = c; row < ROWS && col < COLS; row++,col++){
                mat[row][col] = diagonal[k++];
            }
            
        }
        
        return mat;
    }
};
/*






*/