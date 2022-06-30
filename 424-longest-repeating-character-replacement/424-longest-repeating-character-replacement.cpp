class Solution {
public:
    int characterReplacement(string s, int k) {
        int window_start  =0;
        vector<int> letter(26,0);
        int maxlength =0;
        int maxletter =0;
        for(int window_end = 0;window_end<s.size();window_end++){
            letter[s[window_end]-'A']++;
            maxletter = max(maxletter,letter[s[window_end]-'A']);
            while(window_end-window_start-maxletter+1>k){
                letter[s[window_start]-'A']--;
                window_start++;
            }
            maxlength = max(maxlength,window_end-window_start+1);
        }
        return maxlength;
    }
};