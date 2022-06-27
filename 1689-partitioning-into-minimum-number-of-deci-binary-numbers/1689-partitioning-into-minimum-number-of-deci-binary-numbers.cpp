class Solution {
public:
    int minPartitions(string n) {
        int k = 1;
        for(int i=0;i<n.size();i++){
            k = max(k,n[i]-'0');
        }
        // ans will be number of max mum digit present in string n
        return k;
    }
};