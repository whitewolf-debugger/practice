class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int L = 0;
        int ans = 0;
        int currCost = 0;
        for(int R = 0 ; R < s.size(); R++) {
            currCost += abs(s[R] - t[R]);
            while(L < s.size() && currCost > maxCost) {
                currCost -= abs(s[L] - t[L]);
                L++;
            }
            ans = max(ans, R - L + 1);
        }
        return ans;
    }
};