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
Scanning from left to right our force decays by 1 every iteration, and resets to N if we meet an 'R', so that force[i] is higher (than force[j]) if and only if dominoes[i] is closer (looking leftward) to 'R' (than dominoes[j]).

Similarly, scanning from right to left, we can find the force going rightward (closeness to 'L').

For some domino answer[i], if the forces are equal, then the answer is '.'. Otherwise, the answer is implied by whichever force is stronger.


*/