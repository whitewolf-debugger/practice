class Solution {
public:
    long long dp(string &s,int i,vector<long long> & cache){
        if(i >= s.size()){
            return 1;
        }
        if(cache[i]!= -1) return cache[i];
        long long curr = s[i] - '0';
        long long takeOne = 0;
        long long takeTwo = 0;
        if(curr != 0){
            takeOne += dp(s,i+1,cache);
        }
        if(i+1 < s.size()){
            int next = s[i+1] - '0';
            if(curr == 1 ||(curr == 2 && next <= 6)){
                takeTwo += dp(s,i+2,cache);
            }
        }
        return cache[i] = takeOne + takeTwo;
    }
    int numDecodings(string s) {
        vector<long long> cache(100,-1);
        long long ans = dp(s,0,cache);
        return ans;
    }
};