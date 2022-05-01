class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;
        for(int i=0;i<s.size();i++){
            if(s[i]!='#'){
                s1.push(s[i]);
            }
            else{
                if(!s1.empty()) s1.pop();
            }
        }
        for(int j=0;j<t.size();j++){
            if(t[j]!='#'){
                s2.push(t[j]);
            }
            else{
                if(!s2.empty()) s2.pop();
            }
        }
        if(s1.size()!=s2.size()) return false;
        while(!s1.empty()){
            if(s1.top()!=s2.top()) return false;
            s1.pop();
            s2.pop();
        }
        return true;
    }
};