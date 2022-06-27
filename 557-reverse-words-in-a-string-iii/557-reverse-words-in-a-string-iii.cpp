class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');
        string ans="";
        string temp ="";
        for(int i=0;i<s.size();i++){
            temp=temp+s[i];
            if(s[i]==' '){
                reverse(temp.begin(),temp.end());
                ans = ans + temp;
                temp.clear();
            }
        }
        ans.erase(ans.begin());
        return ans;
    }
};