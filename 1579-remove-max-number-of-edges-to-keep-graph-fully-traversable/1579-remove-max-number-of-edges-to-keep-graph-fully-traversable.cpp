//compare is used in sort() inside to sort based on type of edges 
static bool compare(vector<int> &a, vector<int> &b) {
    return a[0] > b[0];
}
class Solution {
public:
    int find(vector<int> &parent, int i) {
        while(parent[i] != i) {
            i = parent[i];
        }
        return i;
    }
    //unioon operation based on rank
    bool unite(vector<int> &parent, vector<int> &rank, int x, int y) {
        int X = find(parent, x);
        int Y = find(parent, y);
        if(X == Y) return false;
        if(rank[X] < rank[Y]) {
            parent[X] = Y;
        }
        else if(rank[X] == rank[Y]) {
            parent[Y] = X;
            rank[X]++;
        } else {
            parent[Y] = X;
        }
        return true;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int ans = 0;
        //type1 keeps track of parent in DSU of Alice's graph
        vector<int> type1(n + 1);
        //type1rank keeps track of parent in DSU of Alice's graph
        vector<int> type1rank(n + 1,0);
        // initializes parent[i] = i initially as intially every node is parent of itself before union 
        iota(type1.begin(), type1.end(),0);
        //type2 keeps track of parent in DSU of BOB's graph
        vector<int> type2(n + 1);
        //type2rank keeps track of rank in DSU of BOB's graph
        vector<int> type2rank(n + 1,0);
        iota(type2.begin(), type2.end(),0);
        //sort edges so that we start uniting from type 3 as type 3 is necessary for both alice and bob 
        //later extra can be removed 
        sort(edges.begin(),edges.end(),compare);
        for(auto edge : edges) {
            int type = edge[0];
            int p = edge[1];
            int q= edge[2];
            if(type == 2) {
                //if unite return true means we were able to add that edge to bobs graph
                //if we were not able to unite it mean it formed cycle 
                //then we increase the ans coz we donot need that node 
                if(!unite(type2,type2rank,p,q)) {
                    ans++;
                }
            } else if(type == 3) {
                //if this edge can be used by both alice and bob 
                //check whether we can add this to alices graph
                //if true means we have united these nodes  then we try to add to bobs graph
                if(!unite(type1,type1rank,p,q)) {
                    //if this returns false then we are unable to unite them 
                    //the nodes are already uniterd in alices graph 
                    //adding this node will cause cycle 
                    //so this edge can be removed 
                    ans++;
                } else {
                    if(!unite(type2,type2rank,p,q)) {
                        //if this returns false then we are unable to unite them 
                        //the nodes are already uniterd in bobs graph 
                        //adding this node will cause cycle 
                        //so this edge can be removed 
                        ans++;
                    }
                }
            } else {
                //if we are not able to add this type 1 edge to alices graph 
                //that means those vertex hare already connected 
                //adding this will create cycle so we dont need it and increase the ans 
                if(!unite(type1,type1rank,p,q)) {
                    ans++;
                }
            }
        }
        //count the number of set parents for both Alice and bobs graph
        //if there are more than one parents for any of them
        //means the graph is not connected 
        //so return -1 else return the ans 
        int parents1 = 0;
        int parents2 = 0;
        for(int i = 1; i <= n; i++) {
            if(type1[i] == i) {
                parents1++;
            }
            if(type2[i] == i) {
                parents2++;
            }
        }
        //return ans if the graph is connected for both alice and bob else return -1
        return (parents1 == 1 && parents2 == 1)? ans : -1;
    }
};