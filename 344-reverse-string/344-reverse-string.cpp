class Solution {
public:
    void reverseString(vector<char>& s) {
        char t;
        int start =0;
        int end = s.size()-1;
        while(start<=end){
            t = s[start];
            s[start] = s[end];
            s[end] =t;
            start++;
            end--;
        }
    }
};