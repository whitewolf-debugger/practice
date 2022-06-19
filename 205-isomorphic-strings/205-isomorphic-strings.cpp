class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,char> mp2;
        unordered_map<char,char> mp;
        for(int i=0;i<s.size();i++){
            //if we encounter a character again while traversing then reutrn check for perfect mapping 
            if(mp[s[i]]!='\0'){
               if(mp[s[i]]!=t[i]) return false;
            }
            else{
                //every character of string 1 maps to every character of string 2
                mp[s[i]]=t[i];
            }
        }
        for(int i=0;i<s.size();i++){
            //if there is repeat
            if(mp2[t[i]]!='\0'){
                //if similar charater is mapped to different character ans is false 
               if(mp2[t[i]]!=s[i]) return false;
            }
            else{
                //every character of string 2 maps to every character of string 1
                mp2[t[i]]=s[i];
            }
        }
        return true;
    }
};