class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int maxlen = 0;
        stk.push(-1);
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                stk.push(i);
            }
            else{
                stk.pop();
                if(stk.empty()){
                    stk.push(i);
                }
                else{
                    maxlen= max(maxlen,i-stk.top());
                }
            }
        }
        return maxlen;
    }
};