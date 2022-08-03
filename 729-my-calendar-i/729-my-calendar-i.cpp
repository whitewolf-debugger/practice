//creating  node of the tree where each node has 2 values 
/*left children have StartDte and EndDate lower than the startDate and endDate of the parent 
right childrens have StartDte and EndDate greater than the startDate and endDate of the parent 
*/
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
    //checks wheteher we can book or not 
    bool book(Node* root ,int start,int end){
        //if there is an empty space to book then we return true
        if(!root) return true;
        // if the start date of current root(movie) is after the end (end || startDate || endDate)
        else if(root->startDate>=end){
            //check of left is null means there is an empty place  return true
            if(!root->left){
                return true;
            }
            // left is not empty so we search for empty place in lefy since start date of current root is after the end  
            else{
                return book(root->left,start,end);
            }
        }
        // if the start date of current root(movie) is after the end (startDate || endDate || starts)
        else if(root->endDate<=start){
            //then we check if there is place in right if there is place then return true;
            if(!root->right){
                return true;
            }
            //look for free time in right
            else{         
                return book(root->right,start,end);
            }
        }
        //if we donot get any free space then return false
        else{
            return false;
        }
    }
    //update helps to update the nodes 
    Node* update(Node* node,int start,int end){
        //if there is  no node then add an edge there 
        if(!node){
            Node* newNode = new Node(start,end);
            return newNode;
        }
        else{
            // if the start date of current root(movie) is after the end (end || startDate || endDate)
            if(node->startDate>=end){
                node ->left = update(node->left,start,end);
            }
            // if the start date of current root(movie) is after the end (startDate || endDate || starts)
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