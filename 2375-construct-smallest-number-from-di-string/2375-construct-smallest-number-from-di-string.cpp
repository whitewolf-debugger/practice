class Solution {
public:
    void backtrack(string &pattern, int i, string &path,string &ans,unordered_set<char> &seen){
        if(i>=pattern.size()){
            ans = min(ans,path);
            return;
        }
        for(char c = '1'; c <= '9'; c++){
            if(seen.find(c) != seen.end()) continue;
            if(pattern[i] == 'I'){
                if(c > path.back()){
                    path.push_back(c);
                    seen.insert(c);
                    backtrack(pattern,i+1,path,ans,seen);
                    seen.erase(c);
                    path.pop_back();
                }
            } else{
                if(c < path.back()){
                    path.push_back(c);
                    seen.insert(c);
                    backtrack(pattern,i+1,path,ans,seen);
                    seen.erase(c);
                    path.pop_back();
                }
            }
        }
    }
    string smallestNumber(string pattern) {
        string path = "";
        string ans = "ZZZZZZZZZZZ";
        unordered_set <char> seen;
        
        for(char c ='1'; c <='9'; c++){
            path.push_back(c);
            seen.insert(c);
            backtrack(pattern, 0 , path, ans, seen);
            seen.erase(c);
            path.pop_back();
        }
        return ans;
    }
};