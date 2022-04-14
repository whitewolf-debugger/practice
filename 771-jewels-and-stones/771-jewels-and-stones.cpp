class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> mp;
        int sum=0;
        for(int i=0;i<stones.size();i++){
            mp[stones[i]]++;
        }
        for(int j=0;j<jewels.size();j++){
            sum+=mp[jewels[j]];
        }
        return sum;
    }
};