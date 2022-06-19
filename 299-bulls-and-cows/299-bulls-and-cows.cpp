class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> ans;
        unordered_map<char,int> track;
        for(int i = 0;i<secret.size();i++){
            track[secret[i]]++;
        }
        for(int i = 0;i<secret.size();i++){
                if(secret[i] == guess[i]){
                    ans['B']++;
                }
        }
        for(int i = 0;i<secret.size();i++){
            if(track[guess[i]]>0){
                track[guess[i]]--;
                ans['C']++;
            }
        }
        ans['C']-=ans['B'];
        string sol = to_string(ans['B'])+"A"+to_string(ans['C'])+"B";
        return sol;
    }
};