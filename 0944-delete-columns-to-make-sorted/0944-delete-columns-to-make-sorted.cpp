class Solution {
    //checks whether the sting is lexicographic or not  
    bool isLexicoGraphic(string &word) {
        //create copy of the original string
        string copy = word;
        //sort the copy string 
        sort(copy.begin(), copy.end());
        
        // check whether sorted copy string is same as the original one it it isnt then return false 
        for(int i =0; i < copy.size(); i++) {
            if(copy[i] != word[i]) {
                return false;
            }
        }
        
        //else return true 
        return true;
    }
    
public:
    
    int minDeletionSize(vector<string>& strs) {
        
        //ans stores the final ans 
        int ans = 0;
        
        //the number of rows = number of string in the vector of strings 
        int COLS = strs[0].size();
        int ROWS = strs.size();
        
        // stores the string  in form of 2D character array
        vector<vector<char>> grid(ROWS, vector<char>(COLS));
        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                grid[r][c] = strs[r][c];
            }
        }

        //make new string column wise 
        for(int c = 0; c < COLS; c++) {
            string currWord = "";
            for(int r = 0; r < ROWS; r++) {
                currWord += grid[r][c];
            }
            
            // check if the string we made using columns is lexicographical  or not 
            if(!isLexicoGraphic(currWord)) {
                //if it isnt then increase the ans 
                ans++;
            }
        }

        // return ans 
        return ans;
    }
};