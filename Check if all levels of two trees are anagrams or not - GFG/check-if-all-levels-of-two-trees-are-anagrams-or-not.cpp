//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //gets the height
    int getHeight(Node* root) {
        if(!root) return 0;
        return 1+getHeight(root -> left) + getHeight(root -> right);
    }
    bool isAnagram(vector<int> &a ,vector<int> &b) {
        if(a.size() != b.size()) return false;
        unordered_map<int , int> mp;
        for(int i =0 ;i < a.size();i++) {
            mp[a[i]]++;
        }
        for(int i =0 ;i < b.size();i++) {
            if(mp[b[i]] <= 0) return false;
            mp[b[i]]--;
        }
        return true;
    }
    //gets data at every level
    void GetData(Node* root, vector<vector<int>>& tree,int level) {
        
        if(!root) return;
        tree[level].push_back(root -> data);
        GetData(root -> left , tree , level + 1);
        GetData(root -> right , tree , level + 1);
    }
    
    bool areAnagrams(Node *root1, Node *root2) {
        vector<vector<int>> tree1;
        vector<vector<int>> tree2;
        int height1 = getHeight(root1);
        int height2 = getHeight(root2);
        tree1.resize(height1);
        tree2.resize(height2);
        if(height1 != height2) return false;
        GetData(root1, tree1 , 0);
        GetData(root2, tree2 , 0);
        for(int i =0 ; i < height1;i++) {
            if(!isAnagram(tree1[i],tree2[i])) return false;
        }
        return true;
        
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}

// } Driver Code Ends