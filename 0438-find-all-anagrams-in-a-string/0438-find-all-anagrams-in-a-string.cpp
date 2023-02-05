class Solution {
public:
    bool isEqual(vector<int> &freqMap, vector<int> &windowMap) {
        //check whether the maps are same means did we get anagram 
        for(int i = 0 ; i < 26; i++) {
            if(windowMap[i] != freqMap[i]) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        //freqmap stores the frequency of element in p
        vector<int> freqMap(26, 0);
        //stores the frequency of element in window in s of size p 
        vector<int> windowMap(26, 0);
        //making frequency map for p
        for(int i = 0 ; i < p.size(); i++) {
            freqMap[p[i]-'a'] += 1;
        }
        //windowstart is intially set to 0
        int windowStart = 0;
        //size of the window will be p.size() 
        int windowSize = p.size();
        for(int windowEnd = 0; windowEnd < s.size();windowEnd++) {
            //increase the frequency of current element (add to the window)
            windowMap[s[windowEnd] - 'a'] += 1;
            //while size of window is more than the size of p(window size) shrink window
            while((windowEnd - windowStart + 1) > windowSize && windowStart < s.size()) {
                //reduce the frequency of element at the start of the window 
                windowMap[s[windowStart] - 'a'] -=1;
                //move windowStart forward (reduce window size)
                windowStart++;
            }

            //check if window is anagram of p by comparing frequency of characters 
            if(isEqual(freqMap, windowMap)) {
                //if yes then push the start index of the window into the ans 
                ans.push_back(windowStart);
            }
        }
        return ans;
    }
};