class Solution {
public:
    vector<int> lettercount(string s){
        vector<int> ans(26,0);
        for(auto & letter: s){
            ans[letter -'a']++;
        }
        return ans;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> hybridfreq(26,0);
        vector<string> ans;
        for(auto& word:words2){
            vector<int> currentWordFreq = lettercount(word);
            for(int i=0;i<26;i++){
                hybridfreq[i]=max(hybridfreq[i],currentWordFreq[i]);
            }
        }
        for(auto& word:words1){
            vector<int> currentWordFreq = lettercount(word);
            bool valid = true;
            for(int i=0;i<26;i++){
                if(currentWordFreq[i]<hybridfreq[i]){
                    valid = false;
                    break;
                }
            }
            if(valid) ans.push_back(word);
         }
        return ans;
    }
};