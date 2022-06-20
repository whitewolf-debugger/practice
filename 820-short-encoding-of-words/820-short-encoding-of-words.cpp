class Solution {
public:
    //this fuction helps us to sort the words according to their size 
    static bool compare(string &s1,string &s2){
        return s1.size() > s2.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        //sorting words accordiong to their size 
        sort(words.begin(),words.end(),compare);
        //base case if there is only one word in the strinf
        // if(words.size()==1){
        //     return (words[0].size()+1);
        // }
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
                    //creating a map of key like time ime me e  
                    cout<<key<<":"<<word<<endl;
                }
            }
        }
        cout<<ans;
        return ans.size();
    }
};