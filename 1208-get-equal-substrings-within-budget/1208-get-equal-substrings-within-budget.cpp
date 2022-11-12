class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        //set the window start
        int windowStart = 0;
        int ans = 0;
        int currCost = 0;
        for(int windowEnd = 0 ; windowEnd < s.size(); windowEnd++) {
            //get the running cost
            currCost += abs(s[windowEnd] - t[windowEnd]);
            //while the running cost is more than max cost reduce the size of the window
            while(windowStart < s.size() && currCost > maxCost) {
                //reduce the current cost reduce the window size 
                currCost -= abs(s[windowStart] - t[windowStart]);
                windowStart++;
            }
            //ans is the maximum length substring with cost
            ans = max(ans, windowEnd - windowStart + 1);
        }
        return ans;
    }
};