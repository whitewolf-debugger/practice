/*iterate through the string , expand from the midddle check for odd and even length palindrome update the ans and ans length */
class Solution {
public:
    //expanding from left and right by L-- and R++ and break when not equal 
    string pali(string &s,int L,int R){
        int n = s.size();
        while(L>=0 && R<n){
            if(s[L]!=s[R]) break;
            L--;
            R++;
        }
        //palindromic sequence we got is  s.substr(L+1,R-L-1)
        return s.substr(L+1,R-L-1);
    }
    //check for best ans which is of max length 
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
        //iterate through string 
        for(int i = 0 ; i<n;i++){
            //get odd length palindrome
            string odd = pali(s,i,i);
            //check which is best previous ans or odd leng string which we got rt now 
            bestAns(odd,ans,ansLen);
            //get even length palindrome
            string even = pali(s,i-1,i);
            //check which is best previous ans or even leng string which we got rt now
            bestAns(even,ans,ansLen);
        }
        //return ans
        return ans;
    }
};