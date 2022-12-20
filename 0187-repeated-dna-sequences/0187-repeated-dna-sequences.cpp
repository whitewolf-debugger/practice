class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> repeated;
        
        set<string> st;
    
        for(int i = 0; i + 9 < s.size(); i++) {
            string curr = s.substr(i, 10);
            if(st.find(curr) != st.end()) {
                repeated.insert(curr);
            } else {
                st.insert(curr);
            }
        }
        vector<string> ans(repeated.begin(),repeated.end());
        return ans;
    }
};