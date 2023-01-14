class Solution {
public:
    int findParent(vector<int> &parent, int i) {
        while(parent[i] != i) {
            i = parent[i];
        }
        return i;
    }

    void merge(int x, int y, vector<int> &parent) {
        int X = findParent(parent, x);
        int Y = findParent(parent, y);

        if(X < Y) {
            parent[Y] = X;
        } else {
            parent[X] = Y;
        }

    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        iota(parent.begin(), parent.end(),0);
        string ans = "";

        for(int i =0; i < s1.size(); i++) {
            merge(s1[i] - 'a' , s2[i] - 'a', parent);
        }

        for(int i = 0 ; i < baseStr.size(); i++) {
            int cur=findParent(parent, baseStr[i]-'a');
            baseStr[i] = cur +'a';
        }


        return baseStr;
    }
};