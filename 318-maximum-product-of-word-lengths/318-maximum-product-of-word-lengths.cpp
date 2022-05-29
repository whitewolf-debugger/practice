class Solution {
public:
    bool compare(bitset<26> &a, bitset<26> &b){
        for(int i=0;i<26;i++){
            if(a[i]==1 && b[i]==1) return true;
        }
        return false;
    }
    int maxProduct(vector<string>& words) {
        int ans =0 ;
        int n = words.size();
        vector<bitset<26>> chars(n);
        for(int i=0;i<words.size();i++){
            for(auto x: words[i]){
                int index  = x -'a';
                chars[i][index]=1;
            }
            for(int j = 0;j<i;j++){
                if(!compare(chars[i],chars[j])){
                    ans = max(ans, (int)words[i].size()*(int)words[j].size());
                }
            }
        }
        return ans;
    }
};