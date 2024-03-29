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
        //base case when all the words have been inserted 
        if(word.size() == 0) {
        //here we donot need is terminal (it has no use in this question still just keeping it)
            root -> isTerminal = true;
            return;
        }
        //get index of the letter at the 0th index of word 
        int idx = word[0] - 'a';
        // this stores the child location
        TrieNode* child ;
        //if there is no child at that position then we need to create and add
        if(root -> children[idx] == NULL) {
            //create trienode which is child 
            child = new TrieNode(word[0]);
            //attatch the child to the parent at its index 
            root -> children[idx]  = child;
        } else {
            //if child is already there then child pointer points to the child 
            child =  root -> children[idx] ;
        }
        //now using recursion continue inserting from tbhe 1st index of word 
        //and we are at the child now we will be now searching for children of child 
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
    //create trie root
    Trie *root = new Trie();
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        //traverse through all the words in the s1
        for(auto s : s1) {
            //add it to the root
            root->insert(s);
            //reverse it and add it to the root
            reverse(s.begin(), s.end());
            //this we will use to check the prefix 
            root->insert(s);
        }
        int ans = 0;
        //for every word in s2
        
        for(auto word: s2) {
            //1st search for prefix
            //if it is prefix to any word in s2 (i.e inserted in trie)
            //then increase count and move next word 
            if(root->search(word) == true) {
                ans++;
                continue;
            }
            //if it is suffix to any word in s2 (i.e inserted in trie)
            //then reverse the word and then search 
            //since we have added the word in reverse to trie to check suffix from the end 
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