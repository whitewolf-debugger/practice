class Solution {
public:
    bool ispal(string &s,int start,int end){
        while(start < end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    
    void dfs(string &s,int start,vector<vector<string>> &ans, vector<string>& current){
        if(start >= s.size()){
            ans.push_back(current);
            return; 
        }
        for(int end = start; end < s.length(); end++){
            if(ispal(s,start,end)){
                current.push_back(s.substr(start,end-start+1));
                dfs(s,end+1,ans,current);
                current.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> current;
        dfs(s,0,ans,current);
        return ans;
    }
};
/*

 



*/