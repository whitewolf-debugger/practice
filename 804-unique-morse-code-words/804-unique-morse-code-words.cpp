class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        unordered_set<string> codes;
        vector<string> morses = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(auto & word : words){
            string curCode = "";
            for(char c : word){
                curCode += morses[c - 'a'];
            }
            codes.insert(curCode);
        }
        return codes.size() ;
    }
};