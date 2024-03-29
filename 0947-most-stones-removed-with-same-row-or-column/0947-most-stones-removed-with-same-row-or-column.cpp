class Solution {
public:
    int find(vector<int> &parent , int i) {
        while(parent[i] != i) {
            i = parent[i];
        }
        return i;
    }
    bool Unite(vector<int> &parent , int x ,int y,vector<int>& rank) {
        int X = find(parent , x);
        int Y = find(parent , y);
        if(X == Y) {
            return false;
        }
        if(rank[X] > rank[Y]) {
            parent[Y] = X;
        } else if(rank[X] < rank[Y]) {
            parent[X] = Y;
        } else {
            parent[Y] = X;
            rank[X]+=1;
        }
        return true;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parent(n);
        vector<int> rank(n,0);
        iota(parent.begin(),parent.end(),0);
        int count = 0;
        for(int i =0 ; i < n;i++) {
            for(int j =i+1; j < n; j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    if(Unite(parent,i,j,rank)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
/*
  [0,0],[0,1]
  [1,0]      [1,2]
        [2,1][2,2]



*/