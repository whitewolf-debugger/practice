class Solution {
public:
    bool compare(vector<int>& mp,vector<int>& um){
        for(int i=0;i<26;i++){
            if(mp[i]!=um[i])return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> phash(26,0);
        vector<int> shash(26,0);
        int n1 = s.size();
        int n2 = p.size();
        vector<int> ans;
        if(s.size()<p.size()) return ans;
        for(int i=0;i<p.size();i++){
            phash[p[i]-'a']++;
            shash[s[i]-'a']++;
        }
        if(compare(phash,shash)) ans.push_back(0);
        for(int i = p.size();i<s.size();i++){
            shash[s[i]-'a']++;
            shash[s[i-p.size()]-'a']--;
            if(compare(shash,phash)){
                ans.push_back(i+1-p.size());
            }
        }
        return ans;
    }
};
/*

   a b a b
   
   a b 
   
   n1 = 4;
   n2 = 2
   




*/