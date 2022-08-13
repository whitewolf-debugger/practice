class Solution {
    bool checkIt(string &s, unordered_map<string , int> &ogMap,int start ,int size,int checkSize){
        int i = start;
        int n  = s.length();
        unordered_map<string ,int> winMap;
        while(i < n){
            string right = s.substr(i,size);
            if(ogMap.find(right)== ogMap.end()){
                return false;
            } else{
                winMap[right]++;
                if(winMap[right]>ogMap[right]){
                    return false;
                }
                if(winMap == ogMap){
                    return true;
                }
                i+=size;
            }
        }
        return false;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        //size of each word in 
        int size  = words[0].size();
        int checkSize = words.size();
        int superLen = size*checkSize;
        unordered_map<string ,int> ogMap;
        for(auto & word : words){
            ogMap[word]++;
        }
        unordered_map<string , int> windowMap;
        int n = s.length();
        for(int i = 0 ; i <= n-superLen; i++){
            if(checkIt(s,ogMap,i,size,checkSize)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};