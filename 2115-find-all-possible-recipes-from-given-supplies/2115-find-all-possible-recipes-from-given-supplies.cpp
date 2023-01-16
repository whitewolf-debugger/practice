class Solution {
public:
    //apply toposort 
    vector<string> findAllRecipes(vector<string>& recipies, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n  = recipies.size();
        queue<string> availableSupply;
        for(auto supply : supplies) {
            availableSupply.push(supply);
        }

        unordered_map<string, int> indegree;
        unordered_map<string,vector<string>> mp;
        unordered_map<string,bool> visited;

        for(int i =0 ; i < recipies.size(); i++) {
            for(int j =0 ; j < ingredients[i].size(); j++) {
                indegree[recipies[i]]++;
                mp[ingredients[i][j]].push_back(recipies[i]);
            }
        }

        while(!availableSupply.empty()) {
            string supply = availableSupply.front();
            availableSupply.pop();
            for(auto & recipie: mp[supply]) {
                indegree[recipie]--;
                if(!indegree[recipie]) {
                    availableSupply.push(recipie);
                    visited[recipie] = true;
                }
            }
        }

        vector<string> ans;

        for(int i =0 ; i< n; i++) {
            if(visited[recipies[i]]) ans.push_back(recipies[i]);
        }
        return ans;
    }
};