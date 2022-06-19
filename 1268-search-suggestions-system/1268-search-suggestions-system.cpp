class Solution {
public:
    static bool my_compare(string a, string b){
    // Check if a string is present as
    // prefix in another string, then
    // compare the size of the string
    // and return the larger size
    if (a.compare(0, b.size(), b) == 0|| b.compare(0, a.size(), a) == 0)
            return a.size() < b.size();
    // Else return lexicographically
    // smallest string
    else
        return a < b;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end(),my_compare);
        vector<vector<string>> ans;
        string key,word;
        unordered_map<string,vector<string>> mp;
        for(int i = 0 ; i< products.size();i++){
           word = products[i];
            for(int j = 1; j<= word.size();j++){
                key = word.substr(0,j);
                mp[key].push_back(word);
            }
        }
        vector<string> data ;
        for(int i = 1 ; i <= searchWord.size();i++){
            key = searchWord.substr(0,i);
            vector<string> sol;
            data = mp[key];
            int k  = 0 ;
            while(k<data.size() && k<3){
                sol.push_back(data[k]);
                k++;
            }
            
            ans.push_back(sol);
        }
        return ans;
    }
};