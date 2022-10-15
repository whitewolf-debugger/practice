int cache[101][101][27][101];
class Solution {
public:
    int dp(string &s,int idx,int lastChar,int lastCharCount, int k,set<int> &st){
        if(k < 0) return INT_MAX/2;
        if(idx >= s.size()) return 0;
        if(cache[idx][k][lastChar][lastCharCount] != -1) return cache[idx][k][lastChar][lastCharCount];
        int keepChar;
        //delete the character 
        int deleteChar = dp(s,idx+1,lastChar,lastCharCount,k-1,st);
        //condition to keep the character 
        if(s[idx] -'a'== lastChar) {
            keepChar = dp(s,idx + 1,lastChar,lastCharCount + 1,k,st) + ((st.find(lastCharCount) != st.end())?1:0);
        } else {
            keepChar = dp(s,idx + 1,s[idx]-'a',1,k,st) + 1;
        }
        int result = min(keepChar,deleteChar);
        return cache[idx][k][lastChar][lastCharCount] = result;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        set<int> st;
        st.insert(1);
        st.insert(9);
        st.insert(99);
        memset(cache,-1,sizeof(cache));
        return dp(s,0,26,0,k,st);
    }
};