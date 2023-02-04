class Solution {
public:
    bool isValid(vector<int> &windowMap, vector<int> &freqMap) {
        //check if maps window map and the frequency maps are true
        for(int i = 0 ; i < 26; i++) {
            //if the maps are not same then return false 
            if(windowMap[i] != freqMap[i]) return false;
        }
        //if we got frequency of of characters in s1 same in window inside s2 then return true
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int windowSize = s1.size();
        //has the map of s1
        vector<int> freqMap(26,0);
        //has the map of current window window of s2
        vector<int> windowMap(26,0);
        //make freqMap
        for(int i =0 ; i < s1.size(); i++) {
            freqMap[s1[i] - 'a']++;
        }
        //window start is at 0
        int windowStart = 0;
        //window End traverses from start to size of s2
        for(int windowEnd = 0; windowEnd < s2.size(); windowEnd++) {
            //increase the frequency of element at window end 
            windowMap[s2[windowEnd] - 'a']++;
            //if the size of current window is more than size of ab then reduce size of window
            while((windowEnd - windowStart + 1) > windowSize) {
                //reduce the freqency of element we just excluded from the window map
                windowMap[s2[windowStart] - 'a']--;
                //move the start forward 
                windowStart++;
            }
            //check if it is Valid if we got permutations of s1 in s2 
            if(isValid(freqMap, windowMap)) return true;
        }
        //we are here means we didnot get permutation 
        return false;
    }
};