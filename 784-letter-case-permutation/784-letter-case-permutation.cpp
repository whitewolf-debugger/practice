class Solution {
public:
    void dfs(string &s,vector<string>&path,int i){
        //base case when current index is more than the size of the element
        if(i >= s.size()){
            //push the  string in path
            path.push_back(s);
            return;
        }
        // if element at current index in the string is 
        if(isalpha(s[i])){
            //first convert to lower case explore all the path
            s[i]=tolower(s[i]);
            dfs(s,path,i+1);
            //convert to upper case explore all the path
            s[i]=toupper(s[i]);
            dfs(s,path,i+1);
        }
        else{
            //if element at that index is digit  we do nothing move to element at next index by i+1
            dfs(s,path,i+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> path;
        //ans is stored in path since we are passing path by reference
        dfs(s,path,0);
        //return path with ans
        return path;
    }
};