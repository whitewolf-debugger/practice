class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() !=word2.size()) return false;
        set<char> ws1;
        set<char> ws2;
        vector<int> freqMap1(26,0) , freqMap2(26,0) ;
        for(int i =0 ;i < word1.size(); i++) {
            freqMap1[word1[i] - 'a']++;
            freqMap2[word2[i] - 'a']++;
            ws1.insert(word1[i]);
            ws2.insert(word2[i]);
        }
        sort(freqMap1.begin() , freqMap1.end());
        sort(freqMap2.begin() , freqMap2.end());
        if(ws2 == ws1 && freqMap1 == freqMap2) return true;
        return false;
    }
};