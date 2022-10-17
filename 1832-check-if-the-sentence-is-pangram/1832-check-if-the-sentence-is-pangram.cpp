class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> st;
        for(auto & letter : sentence){
            st.insert(letter);
        }
        return st.size() == 26; 
    }
};