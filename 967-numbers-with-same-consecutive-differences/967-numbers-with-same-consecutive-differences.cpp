class Solution {
public:
    void dfs(int size,int n,int k,int num,unordered_set<int> &seen,vector<int> &ans){
        if(size == n){
            if(seen.find(num) == seen.end()){
                seen.insert(num);
                ans.push_back(num);
            }
            return;
        }
        
        int LastDigit = num % 10;
        if((LastDigit + k) < 10){
            dfs(size+1,n,k,((num*10)+(LastDigit + k)),seen,ans);
        }
        if((LastDigit - k) >= 0){
            dfs(size+1,n,k,((num*10)+(LastDigit - k)),seen,ans);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        int CurrSize  = 1;
        unordered_set<int> seen;
        vector<int> ans;
        
        for(int i = 1; i < 10; i++){
            dfs(CurrSize,n,k,i,seen,ans);
        }
        return ans;
    }
};