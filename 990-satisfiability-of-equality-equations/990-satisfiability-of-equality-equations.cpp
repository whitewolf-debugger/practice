class Solution {
public:
    //find parent of the set or leader of a set
    int findparent(vector<int> &parent,int i) {
        while(parent[i] != i){
            i = parent[i];
        }
        return i;
    }
    
    //union of 2 nodes 
    void unite(int x,int y,vector<int> &parent,vector<int> &rank) {
        int parentx = findparent(parent,x);
        int parenty = findparent(parent,y);
        //union by rank (optimized method)
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
    
    //we unite the 2 nodes if there is == and after uniting all we check for != if those have same parent means eqn not satisfied
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