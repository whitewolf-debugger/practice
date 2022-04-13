class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        stack<char> q;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{'|| s[i]=='['){
                p.push(s[i]);
            }
            if(s[i]==')'){
                if(p.empty()){
                    return false;
                }
                q.push(s[i]);
                if(p.top()=='('){
                    p.pop();
                    count++;
                }
            }
            if(s[i]=='}'){
                if(p.empty()){
                    return false;
                }
                q.push(s[i]);
                if(p.top()=='{'){
                    p.pop();
                    count++;
                }
            }
            if(s[i]==']' ){
                if(p.empty()){
                    return false;
                }
                q.push(s[i]);
                if(p.top()=='['){
                    p.pop();
                    count++;
                }
            }
        }
        if(!p.empty()){
            return false;
        }
        if(q.size()!=count){
            return false;
        }
        return true;
    }
};