class WordFilter {
public:
    unordered_map<string,int> mp;
    WordFilter(vector<string>& words) {
        string start;
        string end;
        for(int i=0;i<words.size();i++){
            string word = words[i];
            for(int j = 1 ;j<=word.size();j++){
                start = word.substr(0,j);
                for(int k = 0 ; k<word.size();k++){
                    end = word.substr(k,word.size());
                    mp[start+'|'+end]=i+1;
                }
            }
        }
    } 
    int f(string prefix, string suffix) {
        return mp[prefix+'|'+suffix]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */