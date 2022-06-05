class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        for(int i=0;i<nums.size();i++){
            //we are considering index from 1 since element with index = 0 means removed element  for us here 
            m1[nums[i]] = i+1;
            m2[i+1]= nums[i];
        }
        for(int i=0;i<operations.size();i++){
            vector<int> x = operations[i];
            // changing element at that index
            m2[m1[x[0]]] = x[1];
            //add new element to element : index map and index will be the index of previous element
            m1[x[1]] = m1[x[0]];
            //set the index of previous element = 0 means not present 
            m1[x[0]]=0;
        }
        //size of the ans will be same as the the size of intial array
        vector<int> ans(nums.size());
        for(int i =0;i<nums.size();i++){
            //place the element at index i of ans 
            ans[i]=m2[i+1];
        }
        return ans;
    }
};
/*

1 2

1,3 , 2,1  3,2

m1

element    index
1 	  ->  1
2 	  ->  2


element    index
1 	  ->  2
2 	  ->  1
3     ->  0



m2

index  element
1 	-> 	1
2 	-> 	2

index  element
1 	-> 	2
2 	-> 	1





*/