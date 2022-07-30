class Solution {
public:
    //creates a frequency map of all the letters in the word at that index 
    vector<int> lettercount(string s){
        vector<int> ans(26,0);
        for(auto & letter: s){
            ans[letter -'a']++;
        }
        return ans;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        //hybridfreq stores the frequency of the hybrid word we form from words2
        vector<int> hybridfreq(26,0);
        //stores the ans string
        vector<string> ans;
        //making of hybrid string using ferequency of each word in word2 
        for(auto& word:words2){
            vector<int> currentWordFreq = lettercount(word);
            for(int i=0;i<26;i++){
                //combine these words in B to form a "maximum" word , that has the maximum count of every letter in each word in B.
                hybridfreq[i]=max(hybridfreq[i],currentWordFreq[i]);
            }
        }
        //chekcing for word in word 1 
        for(auto& word:words1){
            //get frequency of current of letters of word 
            vector<int> currentWordFreq = lettercount(word);
            bool valid = true;
            for(int i=0;i<26;i++){
                //if there is a word in hybrid whose frequency is more than what is there in the current word frequency of word1 
                if(currentWordFreq[i]<hybridfreq[i]){
                    //word is invalid
                    valid = false;
                    break;
                }
            }
            //if word is valid push in the ans
            if(valid) ans.push_back(word);
         }
        return ans;
    }
};