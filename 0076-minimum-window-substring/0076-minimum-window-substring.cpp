class Solution {
public:
    bool has(unordered_map<char,int>  &mp ,unordered_map<char,int> &um) {
        if(mp.size() > um.size()) return false;
        for (auto & x : mp) {
            if(um[x.first] < x.second) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        unordered_map<char,int> um;
        string ans = "";
        
        //map all the element of string t 
        for(int i =0;i < t.size();i++) {
            mp[t[i]]++;
        }
        int n = s.size();
        int windowStart = 0;
        int windowEnd = 0;  
        int sz = INT_MAX;
        for(;windowEnd < n;windowEnd++) {
            if(mp.find(s[windowEnd]) != mp.end()) {
                um[s[windowEnd]]++;
            } 
            while(has(mp,um)) {
                if(windowEnd - windowStart + 1 < sz) {
                    sz = windowEnd - windowStart + 1 ;
                    ans = s.substr(windowStart,windowEnd - windowStart + 1);
                }
                if(um.find(s[windowStart]) != um.end()) um[s[windowStart]]--;
                windowStart++;
            }
        }
        return ans;
    }
};