class Solution {
public:
    void dfs(string s, vector<string> &ans,int start){
        if(start>=s.size()){
            ans.push_back(s);
            return;
        } 
        if(isalpha(s[start])){
            s[start]=toupper(s[start]);
            dfs(s,ans,start+1);
            s[start]=tolower(s[start]);
            dfs(s,ans,start+1);  
        }
        else{
            dfs(s,ans,start+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        dfs(s,ans,0);
        return ans;
    }
};