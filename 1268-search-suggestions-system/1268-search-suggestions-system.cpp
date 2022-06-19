class Solution {
public:
    static bool my_compare(string a, string b){
    // Check if a string is present as
    // prefix in another string, then
    // compare the size of the string
    // and return the smaller size
    if (a.compare(0, b.size(), b) == 0|| b.compare(0, a.size(), a) == 0)
            return a.size() < b.size();
    // Else return lexicographically
    // smallest string
    else
        return a < b;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        //sort all the listed products lexicographically 
        sort(products.begin(),products.end(),my_compare);
        //sotres the ans 
        vector<vector<string>> ans;
        string key,word;
        //we create a map of substring of words and push back the word in it 
        unordered_map<string,vector<string>> mp;
        for(int i = 0 ; i< products.size();i++){
            //taking word from lexicographically sorted product list
           word = products[i];
            // taking every substring of word and pushing that full word in it
            for(int j = 1; j<= word.size();j++){
                key = word.substr(0,j);
                mp[key].push_back(word);
            }
        }
        vector<string> data ;
        for(int i = 1 ; i <= searchWord.size();i++){
            //making substring of entered word in it since we have to searc h like w wo wor word so on 
            key = searchWord.substr(0,i);
            vector<string> sol;
            data = mp[key];
            int k  = 0 ;
            // if we havenot pushed 3 element and also k< size of data then we push data[k]
            while(k<data.size() && k<3){
                sol.push_back(data[k]);
                k++;
            }
            //push the solution in ans
            ans.push_back(sol);
        }
        return ans;
    }
};