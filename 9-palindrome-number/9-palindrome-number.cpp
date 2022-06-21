class Solution {
public:
    bool isPalindrome(int x) {
        long int reverse =0;
        long int temp =x;
        while(x>0){
            int rem = x%10;
            reverse = reverse*10+rem;
            x=x/10;
        }
        return reverse==temp;
    }
};