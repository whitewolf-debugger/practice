class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> ans;
        unordered_map<char,int> track;
        for(int i = 0;i<secret.size();i++){
            //keeping track of all the character of secret in track
            track[secret[i]]++;
        }
        for(int i = 0;i<secret.size();i++){
                if(secret[i] == guess[i]){
                    //traversing through all the element and if position are same then increasing B(BULLS)
                    ans['B']++;
                }
        }
        for(int i = 0;i<secret.size();i++){
            //traversing though all the element of guess 
            if(track[guess[i]]>0){
                //if we get same character then remove from track and increase cow map 
                track[guess[i]]--;
                ans['C']++;
            }
        }
        //final number of cows  will be (total number same character - total bulls) 
        ans['C']-=ans['B'];
        //creating the string solution
        string sol = to_string(ans['B'])+"A"+to_string(ans['C'])+"B";
        //return solution 
        return sol;
    }
};