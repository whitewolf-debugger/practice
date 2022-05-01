class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count=0;
        for(int i=0;i<words.size();i++){
            bool check = true;
            for(int j=0;j<words[i].size();j++){
                if(words[i].at(j)!=s[j]){
                    check= false;
                    break;
                }
            }
            if(check)count++;
        }
        return count;
    }
};