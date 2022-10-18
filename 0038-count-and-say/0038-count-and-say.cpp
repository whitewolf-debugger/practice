class Solution {
public:
    string helper(string &s) {
        char previous = s[0];
        int count =1;
        string temp ="";
        for(int i =1; i <s.size();i++) {
            if(s[i] == previous) {
                count++;
            } else{
                temp += to_string(count);
                temp += previous;
                count = 1;
                previous = s[i];
            }
        }
        temp += to_string(count);
        temp += previous;
        return temp;
    }
    string countAndSay(int n) {
        string s = "1";
        for(int i =1 ;i < n;i++) {
            s = helper(s);
        }
        return s;
    }
};