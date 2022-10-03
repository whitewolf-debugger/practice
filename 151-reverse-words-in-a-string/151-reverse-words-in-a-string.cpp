class Solution {
public:
    //Reverse the Whole String and Then Reverse Each Word
    string reverseWords(string s) {
        //get the size of the string 
        int n = s.size();
        string  ans = "";
        
        //get the valid start and the end index after removing the blank spaces from the begining and the end 
        int start = 0;
        int end = n-1;
        while(s[start] == ' ') start++;
        while(s[end] == ' ') end--;
        //reverse the valid part of the string after removing ' ' from start and end  
        reverse(s.begin()+start,s.begin()+end+1);
        //curr string stores the current string 
        string curr = "";
        //tarverse from start to end and insert the character  one by one 
        for(int i =start; i <= end;i++){
            //if we are at the end then we donot add ' ' after adding current word to the string 
            if(i == end) {
                //insert the end letter in the string 
                curr +=s[i];
                //reverse the word 
                reverse(curr.begin(),curr.end());
                //insert in the ans 
                ans += curr ;
                //clean the currstring 
                curr.clear();
            }else if(s[i] == ' ') {
                //if we encountered a blank space in between we reverse the current word
                if(curr.empty()) continue;
                reverse(curr.begin(),curr.end());
                //add current word + ' '(blankspace) to the ans 
                ans += curr + ' ';
                //clean the current string 
                curr.clear();
            } else {
                //if its just a normal letter then we add the normal letter to the string 
                curr +=s[i];
            }
        }
        //return ans string 
        return ans;
    }
};
