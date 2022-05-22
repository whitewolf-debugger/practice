class Solution {
public:
    int countSubstrings(string s) {
        int OddPalSubseq =0;
        int EvePalSubseq =0;
        int left;
        int right;
        for(int i=0;i<s.size();i++){
            left =i;
            right=i;
            while(left>=0 && right<s.size() && s[left]==s[right]){
                OddPalSubseq++;
                left--;
                right++;
            }
            left =i;
            right = i+1;
            while(left>=0 && right<s.size() && s[left]==s[right] ){
                EvePalSubseq++;
                left--;
                right++;
            }
        }
        return OddPalSubseq+EvePalSubseq;
    }
};