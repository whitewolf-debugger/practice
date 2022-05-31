class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<k) return false;
        unordered_set<string> combs;
        for(int i = 0 ; i <= s.size()-k;i++){
            if(combs.find(s.substr(i,k))==combs.end()){
                combs.insert(s.substr(i,k));
            } 
        }
        return (combs.size()==pow(2,k));
    }
};