class Solution {
public:
    void backtrack(string s,string temp,unordered_set<string> dict,vector<string> &ans){
        //if we have iterated through the entire size of the string
        if(s=="") {
            //remove gap from the end 
            temp.pop_back();
            //push the temp string in the ans vector 
            ans.push_back(temp);
            return;
        }
        string prefix;
        for(int i=0;i<s.size();i++){
            //get the prefix 
            prefix = prefix+s[i];
            //if it is present in the list 
            if(dict.find(prefix)!=dict.end()){
                //add prefix to the temp 
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