class Solution {
public:
    set<string> st;
    bool DFS(vector<string> &words, int i , int idx) {
        if(idx >= words[i].size()) {
            return true;
        }
        string str = "";

        for(int k = idx; k < words[i].size(); k++) {
            str += words[i][k];
            if(st.find(str) != st.end()) {
                if(DFS(words,i,k + 1)) {
                    return true;
                }
            }
        }
        return false;
    }


    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        for(auto word : words) {
            st.insert(word);
        }
        vector<string> res;
        for(int i =0 ; i < words.size(); i++) {
            st.erase(words[i]);
            if(DFS(words, i, 0)) res.push_back(words[i]);
            st.insert(words[i]);
        }

        return res;
    }
};