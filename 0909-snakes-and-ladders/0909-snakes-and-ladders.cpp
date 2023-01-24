class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<pair<int, int>> cells(n * n + 1);
        int label = 1;
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);
        for (int row = n - 1; row >= 0; row--) {
            for (int column : columns) {
                cells[label++] = {row, column};
            }
            reverse(columns.begin(), columns.end());
        }
        vector<int> distance(n* n + 1 , INT_MAX);
        distance[1] = 0;
        priority_queue<pair<int, int> , vector<pair<int ,int>>, greater<pair<int , int>>> pq;
        pq.push({0,1});
        while(!pq.empty()) {
            auto [currDistance ,currLabel] = pq.top();
            pq.pop();
            for(int i = currLabel + 1 ; i <= min(currLabel + 6, n * n); i++) {
                auto[row , col] = cells[i];
                int destination = board[row][col] == -1 ? i : board[row][col];
                if(distance[destination] > currDistance + 1) {
                    distance[destination] = currDistance + 1;
                    pq.push({distance[destination] , destination});
                }
            }
        }
        return distance[n*n] == INT_MAX ? -1 : distance[n*n];
    }
};
/*

snake or ladder if board[r][c] != -1
Squares 1 and n2 do not have a snake or ladder.

1- > n2 least time 


*/