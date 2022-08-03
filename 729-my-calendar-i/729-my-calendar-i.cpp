class Node{
    public:
    int startDate;
    int endDate;
    Node* left;
    Node* right;
    Node(int startDate,int endDate){
        this->startDate = startDate;
        this->endDate = endDate;
        this->left = NULL;
        this->right = NULL;
    }
};
class MyCalendar {
    public:
    Node* root;
    bool book(Node* root ,int start,int end){
        if(!root) return true;
        else if(root->startDate>=end){
            if(!root->left){
                return true;
            }
            else{
                return book(root->left,start,end);
            }
        }
        else if(root->endDate<=start){
            if(!root->right){
                return true;
            }
            else{
                return book(root->right,start,end);
            }
        }
        else{
            return false;
        }
    }
    Node* update(Node* node,int start,int end){
        if(!node){
            Node* newNode = new Node(start,end);
            return newNode;
        }
        else{
            if(node->startDate>=end){
                node ->left = update(node->left,start,end);
            }
            else{
                node ->right = update(node->right,start,end);
            }
            return node;
        }
    }
    MyCalendar() {
        root =NULL;
    }
    bool book(int start, int end) {
        bool ans = book(root,start,end);
        if(ans){
            root = update(root,start,end);
        }
        return ans;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */