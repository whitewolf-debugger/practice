class Solution {
public:
    string pali(string &s,int L,int R){
        int n = s.size();
        while(L>=0 && R<n){
            if(s[L]!=s[R]) break;
            L--;
            R++;
        }
        return s.substr(L+1,R-L-1);
    }
    void bestAns(string &candidate,string &ans,int &ansLen){
        if(candidate.length()>ansLen){
            ans = candidate;
            ansLen = candidate.length();
        }
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int ansLen =0;
        string ans = "";
        for(int i = 0 ; i<n;i++){
            string odd = pali(s,i,i);
            bestAns(odd,ans,ansLen);
            string even = pali(s,i-1,i);
            bestAns(even,ans,ansLen);
        }
        return ans;
    }
};