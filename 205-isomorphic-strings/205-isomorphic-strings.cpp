class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,char> mp2;
        unordered_map<char,char> mp;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]!='\0'){
               if(mp[s[i]]!=t[i]) return false;
            }
            else{
                mp[s[i]]=t[i];
            }
        }
        for(int i=0;i<s.size();i++){
            if(mp2[t[i]]!='\0'){
               if(mp2[t[i]]!=s[i]) return false;
            }
            else{
                mp2[t[i]]=s[i];
            }
        }
        return true;
    }
};