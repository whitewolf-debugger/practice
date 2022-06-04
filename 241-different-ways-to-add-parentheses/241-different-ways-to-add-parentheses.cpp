class Solution {
public:
    /*once we find the operator split into 2 parts based on the index of operator , then we will recursively call the function to the result of that part */
    vector<int> solutions(string s){
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='+' || s[i]=='-' || s[i]=='*'){
                vector<int> p;
                vector<int> q;
                p = solutions(s.substr(0,i));
                q = solutions(s.substr(i+1));
            
            for(int j=0; j<p.size();j++){
                for(int k =0;k<q.size();k++){
                    if(s[i]=='+'){
                        ans.push_back(p[j]+q[k]);
                    }
                    if(s[i]=='-'){
                         ans.push_back(p[j]-q[k]) ;
                    }
                    if(s[i]=='*'){
                         ans.push_back(p[j]*q[k]);
                    }
                }
            }
        }
    }
     if(ans.size()==0){
            ans.push_back(stoi(s));
    }
    return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        return solutions(expression);
    }
};