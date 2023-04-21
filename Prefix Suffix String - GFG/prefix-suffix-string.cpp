//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class TrieNode {
    public:
    char data;
    TrieNode** children;
    bool isTerminal;
    TrieNode(int data) {
        this -> data = data;
        isTerminal = false;
        children = new TrieNode*[26];
        for(int i = 0 ;i < 26; i++) {
            children[i] = NULL;
        }
    }
};
class Trie { 
    TrieNode* root;
    void insert(TrieNode* root, string word) {
        if(word.size() == 0) return;
        int idx = word[0] - 'a';
        TrieNode* child ;
        if(root -> children[idx] == NULL) {
            child = new TrieNode(word[0]);
            root -> children[idx]  = child;
        } else {
            child =  root -> children[idx] ;
        }
        insert(child,word.substr(1));
    }
    bool search(TrieNode* root,string word) {
        if(word.size() == 0) return true;
        int idx = word[0] - 'a';
        if(root -> children[idx] == NULL) {
            return false;
        } else {
            return search(root -> children[idx],word.substr(1));
        }
    }
    public:
    Trie() {
        root = new TrieNode('\0');
    }
    void insert(string word) {
        insert(root, word);
    }
    bool search(string word) {
        return search(root, word);
    }
};
class Solution{
public:
    Trie *root = new Trie();
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        // Code here
        for(auto s : s1) {
            root->insert(s);
            reverse(s.begin(), s.end());
            root->insert(s);
        }
        int ans = 0;
        for(auto word: s2) {
            if(root->search(word) == true) {
                ans++;
                continue;
            }
            reverse(word.begin(), word.end());
            if(root->search(word) == true) {
               ans++; 
               continue;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends