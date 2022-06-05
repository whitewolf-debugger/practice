class Solution {
public:
    bool help(vector<vector<char>> &board,string &word,int index ,int x,int y,int m,int n,vector<vector<bool>> &visited){
        if(word.size()==index){
            return true;
        }
        if(x<0 || y<0 || x>=board.size() || y>=board[x].size() || visited[x][y]|| word[index]!=board[x][y]){
            return false ;
        }
        visited[x][y] = true;
        if(help(board,word,index+1,x+1,y,m,n,visited)||
            help(board,word,index+1,x-1,y,m,n,visited)||
            help(board,word,index+1,x,y-1,m,n,visited)||
            help(board,word,index+1,x,y+1,m,n,visited)){
            return true;
        }
        visited[x][y]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rowsize = board.size();
        int colsize = board[0].size();
        vector<vector<bool>> visited(rowsize,vector<bool>(colsize,false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0] && help(board,word,0,i,j,rowsize,colsize,visited)){
                    return true;
                }
            }
        }
        return false;
    }
};