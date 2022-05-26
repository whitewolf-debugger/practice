class Solution {
public:
    void dfs(string &s,vector<string>&path,int i){
        if(i >= s.size()){
            path.push_back(s);
            return;
        }
        if(isalpha(s[i])){
            s[i]=tolower(s[i]);
            dfs(s,path,i+1);
            s[i]=toupper(s[i]);
            dfs(s,path,i+1);
        }
        else{
            dfs(s,path,i+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> path;
        dfs(s,path,0);
        return path;
    }
};