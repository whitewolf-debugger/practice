class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        
        for(int i = 0; i <= s.size(); i++){
            if(s[i] == ' ' || i == s.size()){
                reverse(temp.begin() , temp.end());
                if(i != s.size()) temp += ' ';
                ans += temp;
                temp.clear();
            } else {
                temp += s[i];
            }
        }
        return ans;
        
    }
};