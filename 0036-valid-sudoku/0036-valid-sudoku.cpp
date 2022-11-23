class Solution {
public:
    
    bool isValid(unordered_map<char , int>& mp) {

        for(auto &x : mp) {
            if(x.second > 1) return false;
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int ROWS = board.size();
        int COLS = board[0].size();
        unordered_map<char , int> rowMap;
        unordered_map<char , int> colMap;
        unordered_map<char , int> gridMap;
        for(int i =0 ; i < 9; i++) {
            for(int j = 0; j < 9;j++) {
                if(board[i][j] != '.') {
                    rowMap[board[i][j]]++;
                }
                if(board[j][i] != '.') {
                    colMap[board[j][i]]++;
                }
            }
            if(!isValid(rowMap) || !isValid(colMap)) return false;
            rowMap.clear();
            colMap.clear();
        }

        for(int i =0 ; i < 9; i+=3) {
            for(int j = 0; j < 9;j+=3) {
                for(int r = i ; r < i + 3; r++) {
                    for(int c = j; c < j + 3; c++) {
                        if(board[r][c] != '.') {
                            gridMap[board[r][c]]++;
                        }
                    }
                    
                }
                if(!isValid(gridMap)) return false;
                gridMap.clear();
            }
            
        }
        return true;
    }
};