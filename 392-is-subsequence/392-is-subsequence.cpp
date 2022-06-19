class Solution {
public:
    bool isSubsequence(string s, string t) {
        queue<char> q;
        //push all the charracter of string s in a queue ;
        for(int i = 0;i<s.size();i++){
            q.push(s[i]);
        }
        for(int i = 0 ; i<t.size();i++){
            //if the front of queue is = t[i] (since we want character to appear in order)
            if(q.front() == t[i]){
                //remove that element from queue 
                q.pop();
            }
        }
        //if queue is empty then we got all the character of s in t in the correct order 
        return q.empty();
    }
};