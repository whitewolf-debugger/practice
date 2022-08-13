class Solution {
public:
    int romanToInt(string numeral) {
        unordered_map<char,int> mp;
        int result =0;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        for(int i =0; i < numeral.size(); i++) {
            int num = mp[numeral[i]];
            int nextnum = mp[numeral[i+1]];
            if(num >= nextnum) {
                result = result + num;
            } else{
                nextnum = nextnum - num;
                result = result + nextnum;
                i++;
            }
        }
        return result;
    }
};