class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int ROWS = mat.size();
        int COLS = mat[0].size();
        //stores the diagonal element later we sort the diagonal data using this vecotr
        vector<int> diagonal;
        
        //we are traversing down the row and covering the diagonal starting from row 
        for(int r = 0; r < ROWS; r++){
            
            //clean the diagonal arrays previous data
            diagonal.clear();
            
            // start from row  r and 0 col and as we are going down diagonally we do row++ and col++ together 
            for(int row = r, col = 0; row < ROWS && col < COLS; row++,col++){
                
                // push the elmement in the diagonal matrix 
                diagonal.push_back(mat[row][col]);
            }
            
            //sort the daigonal element
            sort(diagonal.begin() , diagonal.end());
            
            // k is diagonal matrix iterator 
            int k =0;
            
            //store the sorted data back again in the original matrix
            for(int row = r, col = 0; row < ROWS && col < COLS; row++,col++){
                mat[row][col] = diagonal[k++];
            }
            
        }
        
        //we have covered the diagonal starting from row now we want to cover diagonal starting from the column 
        for(int c = 0; c < COLS; c++){
            
            //clean the diagonal arrays previous data
            diagonal.clear();
            
            // start from row  0 and  col = c and as we are going down diagonally we do row++ and col++ together 
            for(int row = 0, col = c; row < ROWS && col < COLS; row++,col++){
                
                // push the elmement in the diagonal matrix 
                diagonal.push_back(mat[row][col]);
            }
            
            //sort the diagonal elements
            sort(diagonal.begin() , diagonal.end());
            
            // k is diagonal matrix iterator 
            int k =0;
            
             //store the sorted data back again  in the original matrix
            for(int row = 0, col = c; row < ROWS && col < COLS; row++,col++){
                mat[row][col] = diagonal[k++];
            }
            
        }
        
        //return the ans matrix
        return mat;
    }
};
/*






*/