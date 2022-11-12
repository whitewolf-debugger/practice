class Solution {
public:
    int countDistinct(vector<int> &freqMap) {
        int count = 0 ;
        int distinct = 0;
        for(int i = 0 ; i < freqMap.size(); i++) {
            if(freqMap[i] != 0) {
                distinct++;
            }
        }
        return distinct;
    }
    int numSplits(string s) {
        vector<int> um(26,0);
        vector<int> mp(26,0);
        for(int i =0 ; i < s.size();i++) {
            um[s[i] - 'a']++;
        }
        int ans = 0;
        for(int i =0 ; i < s.size();i++) {
            mp[s[i] - 'a']++;
            um[s[i] - 'a']--;
            if(countDistinct(um) ==countDistinct(mp)) {
                ans++;
            }
            
        }
        return ans;
    }
};
/*

    aacaba
    1) count the number of letters
    2) till current traversal count all freq
    3) reduce the freq in prevmap 
    4) increase in new map 



*/