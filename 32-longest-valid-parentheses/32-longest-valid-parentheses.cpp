class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int maxlen = 0;
        //we start by pushing -1 onto the stack.
        stk.push(-1);
        for(int i=0;i<s.size();i++){
            // For every ‘(’ encountered, we push its index onto the stack.
            if(s[i]=='('){
                stk.push(i);
            }
            else{
                //we pop the topmost element
                stk.pop();
                //If the stack becomes empty, we will push the current element's index onto the stack.
                if(stk.empty()){
                    stk.push(i);
                }
                // else difference between the current element's index and the top element of the stack might be max length.
                else{
                    maxlen= max(maxlen,i-stk.top());
                }
            }
        }
        return maxlen;
    }
};
/*
            Instead of finding every possible string and checking its validity, we can make use of a stack while                           scanning the given string to:
            Check if the string scanned so far is valid.
            Find the length of the longest valid string.
            In order to do so, we start by pushing -1 onto the stack. 
            For every ‘(’ encountered, we push its index onto the stack.
            For every ‘)’ encountered, we pop the topmost element. Then, the length of the currently                                       encountered valid string of parentheses will be the difference between the current element's index and the                     top element of the stack.
            If, while popping the element, the stack becomes empty, we will push the current element's index onto the                       stack. In this way, we can continue to calculate the length of the valid substrings and return the length of                   the longest valid string at the end.

*/