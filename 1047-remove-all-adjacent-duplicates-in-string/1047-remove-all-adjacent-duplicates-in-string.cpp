class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for(int i =0 ; i< s.size(); i++) {
            if(!stk.empty()) {
                if(s[i] == stk.top()) {
                    stk.pop();
                } else {
                    stk.push(s[i]);
                }
            } else {
                stk.push(s[i]);
            }
        }
        string ans = "";
        while(!stk.empty()) {
            char front = stk.top();
            ans.push_back(front);
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};