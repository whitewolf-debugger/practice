class Solution {
public:
    bool isSafeRow(vector<vector<char>> &board,int row,char num){
        for(int i=0;i<9;i++){
            if(board[row][i]==num){
                return false;
            }
        }
        return true;
    }
    bool isSafeCol(vector<vector<char>> &board,int col,char num){
        for(int j=0;j<9;j++){
            if(board[j][col]==num){
                return false;
            }
        }
        return true;
    }
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
    bool solvesudoku(vector<vector<char>>&board){
        int row;
        int col;
        if(!isEmptySpace(board,col,row)){
            return true;
        }
        for(int i=1;i<=9;i++){
            if(isSafe(board,(i+48),row,col)){
                board[row][col]= (char)(i+48);
                if(solvesudoku(board)){
                    return true;
                }
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
            bool ans =solvesudoku(board);
    }
};
