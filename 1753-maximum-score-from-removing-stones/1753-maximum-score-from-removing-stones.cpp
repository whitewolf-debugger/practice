class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int result = 0;
        while(!pq.empty()){
            int bigger = pq.top();
            pq.pop();
            int big = pq.top();
            pq.pop();
            if(bigger ==0 || big == 0) break;
            result ++;
            pq.push(bigger-1);
            pq.push(big-1);
        }
        return result;
    }
};
/*
ans = 4

    pq {
        0
    };
*/