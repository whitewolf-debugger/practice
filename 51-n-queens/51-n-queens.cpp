class Solution {
public:
    bool isPlacable(int n,int row,int column,vector<vector<int>>&board){
        for(int i = row-1;i>=0;i--){
            if(board[i][column]==1){
                return false;
            }
        }
        //checking for upper left
        for(int i=row-1,j=column-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]==1){
                return false;
            }
        }
        //checking for upper right
        for(int i = row-1,j=column+1;i>=0 && j<n;i--,j++){
            if(board[i][j]==1){
                return false;
            }
        }
        return true;
    }
    void nQueenHelper(int n,int row,vector<vector<int>>& board,vector<vector<string>>& sol){
        if(row==n){
            vector<string> v;
            for(int i=0;i<n;i++){
                string str="";
                for(int j=0;j<n;j++){
                    if(board[i][j]==0){
                        str+=".";
                    }
                    else{
                        str+="Q";
                    }
                }
                v.push_back(str);
            }
            sol.push_back(v);
            return;
        }
        for(int j=0;j<n;j++){
            if(isPlacable(n,row,j,board)){
                board[row][j]=1;
                nQueenHelper(n,row+1,board,sol);
                board[row][j]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sol;
        vector<vector<int>> board(n+3,vector<int>(n+3,0));
        nQueenHelper(n,0,board,sol);
        return sol;
    }
};