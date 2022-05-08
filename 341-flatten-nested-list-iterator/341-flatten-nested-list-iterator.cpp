/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    //v stores the integer values of the list
    vector<int> v;
    //pos stores the current posirtion of the iterator
    int pos=0;
    void flatten(vector<NestedInteger> &nestedList){
        // x iterates nestedList vector
        for(auto x: nestedList){
            //x is a list  we  push integer inside of it in a vector
            if(x.isInteger()){
                v.push_back(x.getInteger());
            }
            //if x is adress of a list then we call flatten function again on x.getlist()
            else{
                flatten(x.getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }
    int next() {
        //return the element at that position
        return v[pos++];
        //increase position by one 
    }
    
    bool hasNext() {
        // if position of pointer is less than size of vector  means it has next 
        if(pos<v.size()) {
            return true;
        }
        // we came out of if means position is = v.size() means we are poiting at system memory
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */