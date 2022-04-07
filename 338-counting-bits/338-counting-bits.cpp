class Solution {
public:
    int counter(vector<int> binary){
        int n = binary.size();
        int total =0;
        for(int i=0;i<n;i++){
            if(binary[i]==1){
                total++;
            }
        }
        return total;
    }
    vector<int> binaryconv(int n){
        vector<int> b;
        int rem;
        while(n>0){
            rem = n%2;
            b.push_back(rem);
            n=n/2;
        }
        return b;
    }
    vector<int> countBits(int n) {
        vector<int> v;
        for(int i=0;i<=n;i++){
            vector<int> temp  = binaryconv(i);
            int c = counter(temp);
            v.push_back(c);
        }
        return v;
    }
};