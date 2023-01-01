class Solution {
    //check if the current window is Valid
    bool isValid(unordered_map<char, int> &mp) {
        return (mp['a'] >= 1 && mp['b'] >= 1 && mp['c'] >= 1);
    }
public:

    int numberOfSubstrings(string s) {

        //make windowStart which is intially at 0;
        int windowStart = 0;
        int n = s.size();

        int ans = 0;
        //map helps to track the frequncy of characters in map
        unordered_map<char, int> mp;
        for(int windowEnd = 0; windowEnd < n; windowEnd++) {
            mp[s[windowEnd]]++;
            // till the map is valid we shrink it 
            while(windowStart < windowEnd  && isValid(mp)) {
                //if we ger abcaaaa so it has  abc + abca + abcaa all valid subsequence which we add up
                ans +=  s.size() - windowEnd;
                //decrease the window 
                mp[s[windowStart]]--;
                windowStart++;
                
            }
        }

        //return ans
        return ans;
    }
};