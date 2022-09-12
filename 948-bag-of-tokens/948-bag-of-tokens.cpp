class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int L = 0;
        int R = n-1;
        int ans = 0;
        int points = 0;
        
        while(L <= R && (power >= tokens[L] || points > 0)){
            while(L <= R && power >= tokens[L] ){
                power -= tokens[L];
                L++;
                points++;
            }
            ans = max(ans,points);
            if(L <= R && points > 0){
                power += tokens[R];
                R--;
                points--;
            }
        }
        return ans;
        
        
    }
};
/*






*/