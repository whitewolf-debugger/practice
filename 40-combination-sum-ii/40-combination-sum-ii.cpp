class Solution {
public:
    
    vector<vector<int>>ans;
    vector<int >v;
    
    void solve(vector<int>& candidates, int target,int x){
        
        if(target==0){
            ans.push_back(v);
            return;
        }
        
        for(int i=x;i<candidates.size();i++){
            if(i>x && candidates[i]==candidates[i-1])continue;
            
            if(candidates[i]<=target){ 
                    v.push_back(candidates[i]);
                    solve(candidates,target-candidates[i],i+1);
                    v.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size()==0)return ans;
        
        sort(candidates.begin(),candidates.end());
          
        solve(candidates,target,0);
        return ans;
    }
};