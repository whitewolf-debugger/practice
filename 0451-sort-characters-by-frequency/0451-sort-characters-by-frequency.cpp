class Solution {
public:
    string frequencySort(string s) {
        
        vector<pair<int , char>> freqMap;
        unordered_map<char , int> mp;
        
        for(int i =0 ; i < s.size(); i++) {
            mp[s[i]]++;
        }
        
        for(auto& x: mp) {
            freqMap.push_back({x.second , x.first});
        }
        
        string ans = "";
        
        sort(freqMap.rbegin() , freqMap.rend());
        
        for(int i =0 ; i < freqMap.size(); i++) {
            pair<int , char> cur = freqMap[i];
            for(int j =1 ;j <= cur.first; j++) {
                ans += cur.second;
            }    
        }
        
        return ans;
    }
};