class Solution {
public:
    void reverse(vector<char> &s,int start,int end){
        if(start>=end){
            return;
        }
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        reverse(s,start+1,end-1);
    }
    void reverseString(vector<char>& s) {
        int end = s.size()-1;
        int start =0;
        reverse(s,start,end);
    }
};