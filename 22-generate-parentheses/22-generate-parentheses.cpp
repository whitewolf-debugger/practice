class Solution {
public:
    void backtrack(vector<string>& ans,string path,int open,int close,int n){
        //base case the total string should contains n pair means n opening and n closing braces
        if(path.size()==2*n){
            //if the size of opening braces  == size of closing braces then path is pushed into ans and we return
            if(open == close){
                ans.push_back(path);
                return; 
            }
        }
        if(open<n){
            //if number of opening braces are less than the total braces then we add ( to path
            path.push_back('(');
            backtrack(ans,path,open+1,close,n);
            //backtracking step not adding that brace and not increasing open dicovering other possibilities 
            path.pop_back();
        }
        //number of closing braces should be less than number of opening braces 
        if(close<open){
            path.push_back(')');
            backtrack(ans,path,open,close+1,n);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path;
        int open =0;
        int close=0;
        backtrack(ans,path,open,close,n);
        //final ans is stored in ans 
        return ans;
    }
};