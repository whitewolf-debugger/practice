class Solution {
public:
    int removePalindromeSub(string s) {
        int i =0;
        int j =s.size()-1;
        while(i<j){
            //there are a and b only in the string we can remove them in 2 steps 
            if(s[i]!=s[j]) return 2;
            i++;
            j--;
        }
        //if it comes out of the while loop means it is palindrome  and can be removed in 1 step 
        return 1;
    }
};