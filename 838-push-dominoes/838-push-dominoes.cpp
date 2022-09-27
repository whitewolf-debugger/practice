class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> forces(n,0);
        
        int force = 0;
        for(int r = 0; r < n; r++) {
            if(dominoes[r] == 'R') force = n;
            else if(dominoes[r] == 'L') force = 0;
            else {
                force = max(force - 1,0);
            }
            forces[r] += force;
        }
        
        
        force = 0;
        for(int l = n-1; l >= 0 ; l--) {
            if(dominoes[l] == 'L') force = n;
            else if(dominoes[l] == 'R') force = 0;
            else {
                force = max(force - 1,0);   
            }
            forces[l] -= force;
        }
        string ans = "";
        for(auto& f : forces) {
            if(f < 0) {
                ans += 'L';
            } else if(f > 0) {
                ans += 'R';
            } else {
                ans += '.';
            }
        }
        return ans;
    }
};
/*

.L.R...LR..L..



*/