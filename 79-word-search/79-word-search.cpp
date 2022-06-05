class Solution {
public:
    bool help(vector<vector<char>> &board,string &word,int index ,int x,int y,int m,int n,vector<vector<bool>> &visited){
        //base case when we have matched all the character and index is == size of word
        if(word.size()==index){
            return true;
        }
        //check if we are not exceeding the range of array or revisiting the visited array of the current letter at  x y index is not the letter in given string word 
        if(x<0 || y<0 || x>=board.size() || y>=board[x].size() || visited[x][y]|| word[index]!=board[x][y]){
            return false ;
        }
        //marking visited
        visited[x][y] = true;
        if(help(board,word,index+1,x+1,y,m,n,visited)||
            help(board,word,index+1,x-1,y,m,n,visited)||
            help(board,word,index+1,x,y-1,m,n,visited)||
            help(board,word,index+1,x,y+1,m,n,visited)){
            return true;
        }
        //backtracking step unmarking visited so that we can check for next same letters 
        visited[x][y]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rowsize = board.size();
        int colsize = board[0].size();
        vector<vector<bool>> visited(rowsize,vector<bool>(colsize,false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                //calling backtracking at every encounter of 1st letter of string word
                if(board[i][j]==word[0] && help(board,word,0,i,j,rowsize,colsize,visited)){
                    return true;
                }
            }
        }
        return false;
    }
};