class Solution {
public:
    bool compare(bitset<26> &a, bitset<26> &b){
        for(int i=0;i<26;i++){
            //check if there is 1 in any of bits from 1 to 26 im both  a and b
            if(a[i]==1 && b[i]==1) return true;
        }
        //return false if there is no commmon letter 
        return false;
    }
    int maxProduct(vector<string>& words) {
        int ans =0 ;
        int n = words.size();
        vector<bitset<26>> chars(n);
        for(int i=0;i<words.size();i++){
            for(auto x: words[i]){
                //visit every word and place 1 at that index where word is present in the vector
                //{{1,1,0,0,0,0,0,0,..till 26 letters},..and so on till size n}
                int index  = x -'a';
                chars[i][index]=1;
            }
            //check for more words and consecutively update the ans form 0 to i words which have been mapped
            for(int j = 0;j<i;j++){
                //if there is no common letter among them 
                if(!compare(chars[i],chars[j])){
                    //ans  = max of ans and new calcualtion of size 
                    ans = max(ans, (int)words[i].size()*(int)words[j].size());
                }
            }
        }
        return ans;
    }
};