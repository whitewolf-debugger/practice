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
            // OddPalSubseq counts total number of odd sized  palindrome subsequence 
            while(left>=0 && right<s.size() && s[left]==s[right]){
                OddPalSubseq++;
                left--;
                right++;
            }
            left =i;
            right = i+1;
            //EvePalSubseq counts total number of even sized palindrom subsequnce
            while(left>=0 && right<s.size() && s[left]==s[right] ){
                EvePalSubseq++;
                left--;
                right++;
            }
        }
        //total number of even size palindrome subsequence  + total number of odd sized palindrome subsequence
        return OddPalSubseq+EvePalSubseq;
    }
};
/*
     a      a       a       b
            ↑
     ←    center    →
   left--          right++
   
   select a center and expand on both left and right
        
*/