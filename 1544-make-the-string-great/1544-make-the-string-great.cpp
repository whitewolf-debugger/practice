class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(int i =0; i <s.size();i++) {
            if(isupper(s[i])) {
                if(st.empty()) {
                    st.push(s[i]);
                } else {
                    char c = st.top();
                    if(islower(c) && toupper(c) == s[i]) {
                        st.pop();
                    } else {
                        st.push(s[i]);
                    }
                }
            } else {
                if(st.empty())st.push(s[i]);
                else {
                    char c = st.top();
                    if(isupper(c) && tolower(c) == s[i]) st.pop();
                    else st.push(s[i]);    
                }
            }
        }
        string ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};