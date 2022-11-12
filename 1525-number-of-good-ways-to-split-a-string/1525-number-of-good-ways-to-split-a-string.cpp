class Solution {
public:
    //counts number of distinct characters in the map 
    int countDistinct(vector<int> &freqMap) {
        int count = 0 ;
        int distinct = 0;
        for(int i = 0 ; i < freqMap.size(); i++) {
            if(freqMap[i] != 0) {
                distinct++;
            }
        }
        return distinct;
    }
    int numSplits(string s) {
        //keep 2 maps 
        vector<int> um(26,0);
        vector<int> mp(26,0);
        //first map intially has the frequency of all the characters 
        for(int i =0 ; i < s.size();i++) {
            um[s[i] - 'a']++;
        }
        //intialize ans to be 0 at first
        int ans = 0;
        //increase the frequncy in new map with word till 0 to i (mp) and decrease freq of same in (um)
        for(int i =0 ; i < s.size();i++) {
            //doing this we have now map of 2 half 0 to i in mp and i + 1 to end in um 
            mp[s[i] - 'a']++;
            um[s[i] - 'a']--;
            //check whether number of distinct letters in 2 halves are equal or not increase ans 
            if(countDistinct(um) ==countDistinct(mp)) {
                ans++;
            }
            
        }
        //return ans 
        return ans;
    }
};
/*

    a a c | a b a
    um = {
        a:2
        b:1
    }
    
    mp = {
        a:2
        c:1
    }
    
    
    1) count the number of letters
    2) till current traversal count all freqin new map
    3) reduce the freq in prevmap as we iterate 
    4) increase in new map 
    5) check number of distinct in both maps 
    

*/