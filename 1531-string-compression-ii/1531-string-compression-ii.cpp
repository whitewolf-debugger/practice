class Solution {
public:
    int dp(string &s,int idx,char lastChar,int lastCharCount, int k,set<int> &st,unordered_map<int,int> &mp){
        if(k < 0) return INT_MAX/2;
        if(idx >= s.size()) return 0;
        //memoization
        int key = idx * 101 * 101 * 27 +(lastChar - 'a') * 101 * 101 + lastCharCount * 101 + k;
        if(mp.find(key) != mp.end()) return mp[key];
        int keepChar;
        //delete the character 
        int deleteChar = dp(s,idx+1,lastChar,lastCharCount,k-1,st,mp);
        //condition to keep the character 
        if(s[idx] == lastChar) {
            keepChar = dp(s,idx + 1,lastChar,lastCharCount + 1,k,st,mp) + ((st.find(lastCharCount) != st.end())?1:0);
        } else {
            keepChar = dp(s,idx + 1,s[idx],1,k,st,mp) + 1;
        }
        
        int result = min(keepChar,deleteChar);
        //making key to store the result 
        mp[key] = result;
        return result;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        set<int> st;
        st.insert(1);
        st.insert(9);
        st.insert(99);
        unordered_map<int,int> mp;
        return dp(s,0,(char)('a' + 26),0,k,st,mp);
    }
};