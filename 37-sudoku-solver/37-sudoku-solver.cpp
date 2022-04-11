class Solution {
public:
    //checks whther a number is safe in row 
    bool isSafeRow(vector<vector<char>> &board,int row,char num){
        for(int i=0;i<9;i++){
            if(board[row][i]==num){
                return false;
            }
        }
        return true;
    }
    //check whether a number is safe in that column
    bool isSafeCol(vector<vector<char>> &board,int col,char num){
        for(int j=0;j<9;j++){
            if(board[j][col]==num){
                return false;
            }
        }
        return true;
    }
    //checks whether the number is safe in that grid
    bool isSafeGrid(vector<vector<char>> &board,int row,int col,char num){
        int rowfactor = row-(row%3);
        int colfactor = col-(col%3);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i+rowfactor][j+colfactor]==num){
                    return false;
                }
            }
        }
        return true;
    }
    //checks whether the number is placable in that row ,column and that grid returns false other wise 
    bool isSafe(vector<vector<char>> board,char num,int row,int col){
        if(isSafeRow(board,row,num)&& isSafeCol(board,col,num)&& isSafeGrid(board,row,col,num)){
            return true;
        }
        return false;
    }
    bool isEmptySpace(vector<vector<char>> &board,int &col,int &row){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    row =i;
                    col=j;
                    return true;
                }
            }
        }
        return false;
    }
    //the main solver returns true if solvable , false otherwise 
    bool solvesudoku(vector<vector<char>>&board){
        int row;
        int col;
        /*value of row and col is assigned in isEmpty space function where we have passsed it by reference
        if there is any empty space row and col get value of that index*/
        if(!isEmptySpace(board,col,row)){
            //checks whether sudoku is filledor not , if filled means sudoku is solved returns true;
            return true;
        }
        /*we came out of if block which means that sudoku is not yet complete and there are empty spaces in               between*/
        for(int i=1;i<=9;i++){
            //we are checking which number b/w 1 to 9 is placable in that row and column
            if(isSafe(board,(i+48),row,col)){
                board[row][col]= (char)(i+48);
                if(solvesudoku(board)){
                    /* we place that safe number in that place and pass our updated board to solve sudoku
                    if it return true that means we can solve sudoku by placing this number in that grid*/
                    return true;
                }
                /*we cameout of if that means that number we had placed is invalid placing that number we cant                  solve sudoku so we again make that place empty and check for other number */
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
            //ans is stored in &board after function is called
            bool ans =solvesudoku(board);
    }
};
