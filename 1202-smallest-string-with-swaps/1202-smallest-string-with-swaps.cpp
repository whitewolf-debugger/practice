class Solution {

int find(int x,vector<int>& parent){
    if(x==parent[x]){
        return x;
    }
    
    return parent[x]=find(parent[x],parent);
    
}
void Union(int x,int y,vector<int>& parent){
    int px=find(x,parent);
    int py=find(y,parent);
    
    if(px!=py){
        parent[px]=py;
    }
}
public:
string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {

    int n=s.size();
    vector<int> parent(n);
    
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    
    for(int i=0;i<pairs.size();i++){
        Union(pairs[i][0],pairs[i][1],parent);
    }
    
    unordered_map<int,priority_queue<char,vector<char>,greater<char>>> mp;
    
    for(int i=0;i<n;i++){
        mp[find(i,parent)].push(s[i]);
    }
    
    string ans="";
    for(int i=0;i<n;i++){
        int pnode=find(i,parent);
        char ch=mp[pnode].top();
        ans.push_back(ch);
        mp[pnode].pop();
    }
    
    return ans;
}
};