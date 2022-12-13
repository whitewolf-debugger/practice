class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        //check if the end character is 1 then we cannot reach size -1 position in string
        if(s.back() == '1') return false;
        int n = s.size();
        //marking start postion which has 0 as visited;
        s[0] = '2';
        
        int j = 0;
        
        //start traversing the string from the begining 
        for(int i =0; i < n && s[n-1] != '2'; i++) {
            
            //if the current position in the string cannot be visited then we donot do anything
            if(s[i] != '2') continue;
            
            //take the minJump  + i pos and go till maxJump + i and mark it visited i.e '2' if if(s[j] == '0')
            j = max(j , i + minJump);
            while(j < n && j <= i + maxJump) {
                if(s[j] == '0'){
                    s[j] ='2' ;
                }
                j++;
            }
        }
        
        //check if at the end can we visit the last position in the string
        return s[n - 1] == '2';

    }
};