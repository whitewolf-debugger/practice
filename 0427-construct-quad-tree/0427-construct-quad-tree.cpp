/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
//every node has 4 children topLeft topRight bottomLeft bottomRight
class Solution {
public:
    bool leafCheck(vector<vector<int>> &grid, int x, int y, int length) {
        //check if the all the element of grid are equal
        for(int r = x; r < x + length; r++) {
            for(int c = y; c < y + length; c++) {
                //if any of the element of the grid is different then return false 
                if(grid[r][c] != grid[x][y]) return false;
            }
        }
        //we are here means all the element of the grid are same 
        return true;
    }
    Node* build(vector<vector<int>> &grid, int x, int y, int length) {
        //check if the current grid is a leaf 
        if(leafCheck(grid, x,y,length)) {
            //if current grid is a leaf then set the value of leaf as the value of grid
            //set the isLeaf to true
            Node* newNode = new Node(grid[x][y],true);
            return newNode;
        } else {
            //if its not leaf nodde create a new node
            //the value of node can be any but set isLeaf to false 
            Node* newNode = new Node(grid[x][y], false);
            //top left of the grid is starting from x, y  and size will be length/2
            //example if the size of the grid is 8.8 then after divding it into 
            //four 4x4 grids starting from (4x4 grid1 : (0,0)) (4x4 grid2 :(0,4)) (4x4 grid3 (4,0)) (4x4 grid4 :(4,4))
            newNode -> topLeft = build(grid,x,y,length/2);
            newNode -> topRight = build(grid,x,y + length / 2,length/2);
            newNode -> bottomLeft=build(grid,x+ length / 2,y ,length/2);
            newNode -> bottomRight =build(grid,x+ length / 2,y + length / 2,length/2);//return the newNode
            return newNode;
        }
        return NULL;
    }
    Node* construct(vector<vector<int>>& grid) {
        Node* root = build(grid,0,0,grid.size());
        return root;
    }
};