class Solution {
    
    bool isValid(string& s1, string& s2) {
        
        int diff = 0;
        
        int i = 0;
        int j = 0;
        int n1 = s1.length();
        int n2 = s2.length();
        
        while(i < n1 && j < n2) {
            if(s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                j++;
                diff++;
            }
        }
        
        if(j == n2 -1 && i == n1 && diff == 0) return true;
        
        if(diff != 1) return false;
        return i == n1 && j == n2;
    }
    
    int dfs(unordered_map<int, vector<string>>& um, string& cur, unordered_map<string, int>& cashMoney) {
        int n = cur.length();
        
        if(cashMoney.find(cur) != cashMoney.end()) {
            return cashMoney[cur];
        }
        int best = 1;
        for(auto& s : um[n+1]) {
            if(isValid(cur, s)) {
                int maybe = 1 + dfs(um, s, cashMoney);
                best = max(maybe, best);
            }
        }
        return cashMoney[cur] = best;
    }
    
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<int, vector<string>> um;
        unordered_set<string> seen;
        unordered_map<string, int> cashMoney;
        int mn = INT_MAX;
        for(auto& s : words) {
            int n = s.length();
            mn = min(n, mn);
            um[n].push_back(s);
        }
        int ans = 0;
        for(auto& s : words) {
            ans = max(ans, dfs(um, s, cashMoney));
        }
        
        return ans;
    }
};

/*
    cache: {
        bdca: 1
        bda:  2
        ba:   3
        a:    4
        b:    4
        
    }

     ["a","b","ba","bca","bda","bdca"]
     
     um: {
        1: ["a", "b"],
        2: ["ba"]
        3: ["bca", "bda"]
        4: ["bdca"]
     }


*/