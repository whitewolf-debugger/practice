class Solution {
public:
    long long dp(vector<pair<int ,int >> &ageScores, int i, int prev,vector<vector<int>> &cache) {
        //if the index exceeds the current size of age score pair then return 0
        if(i >= ageScores.size()) {
            return 0;
        }
        //memoization step
        if (cache[prev + 1][i] != -1) {
            return cache[prev + 1][i];
        }
        long long takeit  = 0;
        long long leaveit = 0 ;
        //we can take the current player if the small aged player we took before has less score
        //or we can take if we have not taken any player preiously
        if(prev == -1 || ageScores[i].second >= ageScores[prev].second) {
            //we take the player and add his score to the total score 
            // move to next player current player becomes the previous player 
            takeit = dp(ageScores, i + 1, i,cache) + ageScores[i].second;
        } 

        //case 2 donot take it and move to the next player 
        leaveit  = dp(ageScores, i + 1, prev,cache);
        //memoize the returned data the last step of memoization 
        return cache[prev + 1][i] = max(takeit , leaveit);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        //store the pair of age and score
        vector<pair<int , int>> ageScores;

        for(int i  = 0 ; i < scores.size(); i++) {
            ageScores.push_back({ages[i], scores[i]});
        }

        vector<vector<int>> cache(scores.size(), vector<int>(scores.size(), -1));
        //sort the vector according to age and if age is same then less score same age player will be first
        sort(ageScores.begin(), ageScores.end());
        //answer returned by top down dp is stored in ans
        long long ans = dp(ageScores, 0, -1,cache);
        //return ans
        return ans;
    }
};