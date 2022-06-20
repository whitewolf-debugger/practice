class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        for(auto &c:s){
            m[c]++;
        } 
        int ans = 0,isOdd = 1;
        for(auto &x:m){
            ans += x.second;
            if(x.second%2){
                if(isOdd) isOdd = 0;
                else ans--;
            }
        }
        return ans;
    }
    
};