struct segmenttree{
    vector<int> st;
    int n;
    void init(int n){
        this -> n = n;
        st.resize(4*n,0);
    }
    void build(vector<int>& v,int start,int end,int node){
        if(start == end){
            st[node]=v[start];
            return;
        }
        int mid = (start + end) /2;
        //building left subtree 
        build(v,start,mid,2*node+1);
        //building right subtree
        build(v,mid+1,end,2*node+2);
        //going up and adding up child nodes and placing it in the empty position
        st[node]=st[2*node+1]+st[2*node+2];
    }
    int query(int l,int r,int start,int end,int node){
        //no overlapping
        if(start>r || end<l) return 0;
        //complete overlapping
        if(start>=l && end<=r){
            return st[node];
        }
        //partial overlapping 
        int mid = (start+end)/2;
        int q1 = query(l,r,start,mid,2*node+1);
        int q2 = query(l,r,mid+1,end,2*node+2);
        return q1+q2;
    }
    void update(int index,int val,int start,int end,int node){
        if(start ==end){
            st[node] = val;
            return;
        }
        int mid = (start+end)/2;
        if(mid>=index){
            update(index,val,start,mid,2*node+1);
        }
        else{
            update(index,val,mid+1,end,2*node+2);
        }
        st[node]=st[2*node+1]+st[2*node+2];
        return;
    }
    void build(vector<int> v){
        build(v,0,n-1,0);
    }
    int query(int l,int r){
        return query(l,r,0,n-1,0);
    }
    void update(int index,int val){
        update(index,val,0,n-1,0);
    }
};
class NumArray {
public:
    segmenttree tree;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        tree.init(n);
        tree.build(nums);
    }
    void update(int index, int val) {
        tree.update(index,val);
    }
    int sumRange(int left, int right) {
        return tree.query(left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */