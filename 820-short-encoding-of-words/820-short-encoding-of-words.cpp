class Solution {
public:
    //this fuction helps us to sort the words according to their size 
    static bool compare(string &s1,string &s2){
        return s1.size() > s2.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        //sorting words accordiong to their size 
        sort(words.begin(),words.end(),compare);
        //map of substring of words vs the original word 
        unordered_map<string,string> mp;
        //stores the final ans 
        string ans = "";
        //iterating through all the words
        for(int i = 0; i<words.size();i++){
            //stores the word at that index
            string word = words[i];
            //if that word is not in the map means it is suffix  example "me" is suffix of time 
            if(mp[word]!="\0"){
                //then we skip 
                continue;
            }
            //if it is not prefix
            else{
                //add that word and # after that in ans 
                ans=ans+word+"#";
                //map all the substring of word and the orginal word (helps to check suffix)
                for(int j = 0 ;j<word.size();j++){
                    string key = word.substr(j);
                    mp[key] = word;
                    //creating a map of key like time ime me e with original word 
                    //cout<<key<<":"<<word<<endl;
                }
            }
        }
        
        //cout<<ans;
        //return size of the ans
        return ans.size();
    }
};