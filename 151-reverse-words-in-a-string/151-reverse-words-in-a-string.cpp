class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string  ans = "";
        int start = 0;
        int end = n-1;
        while(s[start] == ' ') start++;
        while(s[end] == ' ') end--;
        reverse(s.begin()+start,s.begin()+end+1);
        string curr = "";
        for(int i =start; i <= end;i++){
            if(i == end) {
                curr +=s[i];
                reverse(curr.begin(),curr.end());
                ans += curr ;
                curr.clear();
            }else if(s[i] == ' ') {
                if(curr.empty()) continue;
                reverse(curr.begin(),curr.end());
                ans += curr + ' ';
                curr.clear();
            } else {
                curr +=s[i];
            }
        }
        return ans;
    }
};
/*

curr = ""
"  hello world  "
              ^
    stack {
 
 
 
 
        
        }

*/