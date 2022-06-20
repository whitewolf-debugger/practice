class Solution {
public:
    static bool compare(string &s1,string &s2){
        return s1.size() > s2.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        if(words.size()==1){
            return (words[0].size()+1);
        }
        unordered_map<string,string> mp;
        string ans = "";
        for(int i = 0; i<words.size();i++){
            string word = words[i];
            if(mp[word]!="\0"){
                continue;
            }
            else{
                ans=ans+word+"#";
                for(int j = 0 ;j<word.size();j++){
                    string key = word.substr(j);
                    mp[key] = word;  
                    cout<<key<<":"<<word<<endl;
                }
            }
        }
        cout<<ans;
        return ans.size();
    }
};