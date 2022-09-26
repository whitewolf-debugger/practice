class Solution {
public:
    int findparent(vector<int> &parent,int i) {
        while(parent[i] != i){
            i = parent[i];
        }
        return i;
    }
    
    void unite(int x,int y,vector<int> &parent,vector<int> &rank) {
        int parentx = findparent(parent,x);
        int parenty = findparent(parent,y);
        if(rank[parentx] > rank[parenty]) {
            parent[parenty] = parentx;
        }
        else if(rank[parentx] < rank[parenty]) {
            parent[parentx] = parenty;
        } else {
            parent[parenty] = parentx;
            rank[parentx]++;
        }
        
        
    }
    
    bool equationsPossible(vector<string>& equations) {
        int size = 26;
        vector<int> parent(26);
        vector<int> rank(26,0);
        iota(parent.begin(),parent.end(),0);
        
        for(auto &eqn : equations) {
            if(eqn[1] == '=') {
                int x = eqn[0]-'a';
                int y = eqn[3]-'a';
                unite(x,y,parent,rank);
            }
        }
        
        for(auto &eqn : equations) {
            if(eqn[1] == '!') {
                int x = eqn[0]-'a';
                int y = eqn[3]-'a';
                if(findparent(parent,x) == findparent(parent,y)) {
                    return false;
                }
            }
        }
        return true;
    }
};