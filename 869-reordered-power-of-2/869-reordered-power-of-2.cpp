class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<string> power;
        
        for(int i=0; i<= 30;i++){
            
            int p = pow(2,i);
            string thing = to_string(p);
            sort(thing.begin(),thing.end());
            power.push_back(thing);
        }
        
        string curr = to_string(n);
        sort(curr.begin(),curr.end());
        
        for(int i =0; i <= 30; i++){
            
            if(power[i] == curr) return true;
        }
        
        return false;
    }
};
/*
    






*/