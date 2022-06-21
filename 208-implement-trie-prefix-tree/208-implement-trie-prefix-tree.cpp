//creating trienode which has data and a children poiter
class TrieNode{
public:
    char data;
    TrieNode** children;
    bool isTerminal;
    TrieNode(char data){
        this->data =data;
        children = new TrieNode*[26];
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal = false;
    }
};
class Trie {
    TrieNode* root;
private:
    void insert(TrieNode *root,string word){
        if(word.size()==0){
            //if we reach the last node means we have inserted the word in the trie so we mark last letter as terminal
            root->isTerminal = true;
            return;
        }
        TrieNode* child;
        int index = word[0]-'a';
        //if there is a child at that index means that word is there in the trie then we simply update the child 
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index]=child;
        }
        //recursive call since we want to attatch next word to the current child and increasind word index by 1 
        insert(child,word.substr(1));
    }
    bool search(TrieNode* root,string word){
        if(word.size()==0){
            //if we are at the end of the word and if that node is terminal means that word has been added to the trie
            return root->isTerminal;
        }
        int index = word[0]-'a';
        if(root->children[index]!=NULL){
            return search(root->children[index],word.substr(1));
        }
        else{
            return false;
        }
    }
    bool startsWith(TrieNode* root,string word){
        if(word.size()==0){
            return true;
        }
        int index = word[0]-'a';
        if(root->children[index]!=NULL){
            return startsWith(root->children[index],word.substr(1));
        }
        else{
            return false;
        }
    }
    //since we need root in all the operations we are sending root and work is done in private part of the code
public:
    Trie() {
        root = new TrieNode('\0');
    }
    void insert(string word) {
        insert(root,word);
    }
    bool search(string word) {
        return search(root,word);
    }
    
    bool startsWith(string prefix) {
        return startsWith(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */