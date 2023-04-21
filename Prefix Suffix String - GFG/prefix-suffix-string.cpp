//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class TrieNode {
    public:
    char data;
    //children pointed of array which stores (TrieNode* (TrieNode pointers))
    TrieNode** children;
    //is terminal is used to mark the end of a word 
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
        if(word.size() == 0) {
        //here we donot need is terminal (it has no use in this question still just keeping it)
            root -> isTerminal = true;
            return;
        }
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
    //search in trie if the size of word is 0 then return true
    bool search(TrieNode* root,string word) {
        if(word.size() == 0) return true;
        int idx = word[0] - 'a';
        //if we are not able to find the current child then return false
        if(root -> children[idx] == NULL) {
            return false;
        } else {
            //else return search from next child and and next letter in word to the end 
            return search(root -> children[idx],word.substr(1));
        }
    }
    public:
    //create trie node with the root node as null node 
    Trie() {
        root = new TrieNode('\0');
    }
    //insert the word into the trie
    void insert(string word) {
        //we create a sperate insert function in private since it needs 2 things root + word
        insert(root, word);
    }
    //search the word in the trie
    bool search(string word) {
        //we create a sperate searcg function in private since it needs 2 things root + word
        //to return result
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