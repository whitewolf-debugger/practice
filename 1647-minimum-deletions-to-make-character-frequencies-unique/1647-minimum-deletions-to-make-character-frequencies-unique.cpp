class Solution {
public:
    int minDeletions(string s) {
        int ans = 0;
        unordered_map<int,int> mp;
        for(auto & a:s){
            mp[a]++;
        }
        unordered_set<int> seen;
        for(auto&um:mp){
            if(seen.find(um.second)!=seen.end()){
                while(seen.find(um.second)!=seen.end() && um.second>0){
                    ans++;
                    um.second--;
                }
            }
            seen.insert(um.second);
        }
        return ans;
    }
};