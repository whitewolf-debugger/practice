class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a = "";
        string b = "";
        for(auto & word : word1) {
            a += word;
        }
        for(auto & word : word2) {
            b += word;
        }

        if(a.size() > b.size() || a.size() < b.size()) return false;
        for(int i =0; i < a.size();i++) {
            if(a[i] != b[i]) return false;
        }
        return true;
    }
};