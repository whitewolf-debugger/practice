class Solution {
public:
    int dfs(string &s, int i ,int k, char prev, vector<vector<int>> &cache){
        if(i>=s.length()) return 0;
        
        if(cache[i][prev] != -1) return cache[i][prev];
        
        int take =0;
        int diff = abs(s[i]-prev);
        
        if(prev == '.') {
            diff =0;
        }
                         
        if(diff <= k){
            
            take  = 1 + dfs(s,i+1,k,s[i],cache);
        }
        int leave = dfs(s,i+1,k,prev,cache);
        
        return cache[i][prev] = max(take, leave);
         
    }
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<vector<int>> cache(n, vector<int>(130, -1));
 
        return dfs(s, 0, k, '.', cache);
    }
};