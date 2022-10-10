class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size() == 1) return "";
        int length = palindrome.length();
        for(int i =0; i < length /2;i++){
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[length-1] = 'b';
        return palindrome;
    }
};
/*


A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, a has a character strictly smaller than the corresponding character in b. For example, "abcc" is lexicographically smaller than "abcd" because the first position they differ is at the fourth character, and 'c' is smaller than 'd'.
 

*/