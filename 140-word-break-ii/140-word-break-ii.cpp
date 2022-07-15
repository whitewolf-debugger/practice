class Solution {
public:
    void backtrack(string s,string temp,unordered_set<string> dict,vector<string> &ans){
        if(s=="") {
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        string prefix;
        for(int i=0;i<s.size();i++){
            prefix = prefix+s[i];
            if(dict.find(prefix)!=dict.end()){
                backtrack(s.substr(i+1),temp+prefix+" ",dict,ans);
            }
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<string> ans;
        backtrack(s,"",dict,ans);
        return ans;
    }
};