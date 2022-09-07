class Solution {
public:
    long long dp(string &s,int i,vector<long long> &cache){
        //base case we have traversed through entire s 
        if(i >= s.size()){
            return 1;
        }
        //memoization step 
        if(cache[i]!= -1) return cache[i];
        //take the current number 
        long long curr = s[i] - '0';
        //option 1 take One  eg -: 26 as 2 and 6 and .option 2 is take2 eg 261 as 26 and 1 
        long long takeOne = 0;
        long long takeTwo = 0;
        
        //we can take One only if the current number is not zero since A is 1 and 0 has nio significance 
        if(curr != 0){
            takeOne += dp(s,i+1,cache);
        }
        // we can can chose 2 numbers if i+1 the next index is in range and current number is 1 then 10 to 19 all are valid and for 2 , 20 to 26
        if(i+1 < s.size()){
            int next = s[i+1] - '0';
            if(curr == 1 ||(curr == 2 && next <= 6)){
                takeTwo += dp(s,i+2,cache);
            }
        }
        //memoize the final ans which is sum of the 2 cases take one and take 2 
        return cache[i] = takeOne + takeTwo;
    }
    int numDecodings(string s) {
        //create cache
        vector<long long> cache(100,-1);
        
        //use ans to get the ans through dp
        long long ans = dp(s,0,cache);
        return ans;
    }
};