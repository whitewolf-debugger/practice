class Solution {
public:
    int calculateTime(string keyboard, string word) {
        //make a map of all the letter in the keyboard along with their index
        unordered_map<char , int> mp;
        for(int i =0; i < keyboard.size(); i++) {
            mp[keyboard[i]] = i;
        }
        //ans stores the ans 
        int ans = 0;
        int prev= 0;
        for(auto & c : word) {
            //calculate the diffrence between the previous position and the current one 
            int diff = abs(prev - mp[c]);
            //add the difference which we have to travel to the keyboard 
            ans += diff;
            //the current postion is mp[c] i.e the index of of current letter of word in the keyboard 
            prev = mp[c];
        }

        return ans;
    }
};