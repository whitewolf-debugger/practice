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

/*

"ling   mind    rabo    ofoo    owin    gdin    gbar    rwingmonkeypoundcake"
["fooo","barr","wing","ding","wing"]


                                                |   X   X   X   X   X
0   1   2   3   4   5   6   7   8   9   0   1   2   3   4   5   6   7
b   a   r   f   o   o   t   h   e   f   o   o   b   a   r   m   a   n
                                                |   X   X   X   X   X
                                                ^

ogMap: {
    foo: 1
    bar: 1
}

winMap: 
    foo: 1
}

["foo","bar"]

Output: [0]

1. get length of a word
2. put words in a set/map
3. make another empty set/map
4. sliding window

*/
