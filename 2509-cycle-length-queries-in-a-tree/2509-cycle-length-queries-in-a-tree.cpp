class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> result;

        for(auto& query : queries){
            // get the nodes from the query
            int a = query[0];
            int b = query[1];

            //intial size = 1 for the root where a == b
            int size = 1;

            //move from the node to the root where a == b by dividing the larger value node by 2
            while(a != b) {
                if(a > b) {
                    a = a / 2;
                } else {
                    b = b / 2;
                }
                //increase the size of the cycle every time we move from one node to other
                size += 1;
            }
            //push the calculated size in the result
            result.push_back(size);
        }

        return result;
    }
};
/*
    A cycle is a path that starts and ends at the same node, and each edge in the path is visited only once.

    The length of a cycle is the number of edges visited in the cycle.

    There could be multiple edges between two nodes in the tree after adding the edge of the query.

*/