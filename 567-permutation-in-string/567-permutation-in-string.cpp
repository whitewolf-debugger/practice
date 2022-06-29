class Solution {
public:
    bool matches(vector<int>& mp,vector<int>& um){
        for(int i=0;i<26;i++){
            if(mp[i]!=um[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> mp(26,0);
        //create a map of all the characters stored in s1 
        for(auto& a:s1) mp[a-'a']++;
        //travel till s2.size()-s1.size()
        for(int i=0;i<=s2.size()-s1.size();i++){
            //create a new map  
            vector<int> um(26,0);
            //for every element of s2 map all the elements till size same as size of s1
            for(int j=0;j<s1.size();j++){
                um[s2[i+j]-'a']++;
            }
            //comare the 2 maps if any time we get the 2 maps matched return true;
            if(matches(mp,um)) return true;
        }
        //if maps never matched return false
        return false;
    }
};