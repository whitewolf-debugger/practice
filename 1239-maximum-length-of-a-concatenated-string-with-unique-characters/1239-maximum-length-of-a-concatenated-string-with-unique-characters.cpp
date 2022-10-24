class Solution {
public:
    int backtracking(vector<string>& arr,int idx,unordered_map<char,int> &mp) {
        for(auto & x: mp) {
            if(x.second > 1) {
                return 0;
            }
        }
        int best = mp.size();
        for(int i = idx; i < arr.size();i++) {
            string curr_word = arr[i];
            for(auto& c: curr_word) {
                if(mp.find(c) != mp.end()) {
                    mp[c]++;
                } else {
                    mp[c] = 1;
                }
            }
            best = max(best , backtracking(arr,i+1,mp));
            for(auto& c: curr_word) {
                if(mp[c] == 1) {
                    mp.erase(c);
                } else {
                    mp[c]--;
                }
            }
        }
        return best;
    }
    int maxLength(vector<string>& arr) {
        unordered_map<char,int> freqMap;
        return backtracking(arr,0,freqMap);
    }
};