class Solution {
public:
    bool isPalindrome(string s) {
        string updated;
        for(auto c: s){
            if(isalpha(c)){
                updated.push_back(tolower(c));
            }
            if(isdigit(c)){
                updated.push_back(c);
            }
        }
        string temp = updated;
        int start = 0;
        int end = updated.size() - 1;
        cout<<updated;
        while(start <= end){
            if(updated[start] != updated[end]) return false;
            start++;
            end-- ;
        }
        return true;
    }
};
/*

                R
r   a   c   e   a   c   a   r
    L

*/