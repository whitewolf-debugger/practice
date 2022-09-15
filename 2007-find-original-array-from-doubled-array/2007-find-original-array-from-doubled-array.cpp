class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        //get the size of the changed array
        int n = changed.size();
        vector<int> original;
        
        //if the number of elements are odd or 0 then it means that is not a doubled if doesnot have 2*elements
        if(n == 0 || n%2 != 0){
            return original;
        }
        
        //sort the changed array 
        sort(changed.begin(),changed.end());
        
        //create a map of feqency of element
        unordered_map<int,int> freqMap;
    
        //get the frequency of all the element in the changed array
        for(int i =0; i < n; i++){
            freqMap[changed[i]]++;
        }
        
        //traverse in changed array
        for(auto & x : changed){
            
            //if the current element is not 0 and the frequency of current element is more than 1 and double of that element is there 
            if(x != 0 && freqMap[x] > 0 && freqMap[2*x] > 0){
                
                //add that element to the list and reduce their frequency 
                original.push_back(x);
                freqMap[x]--;
                freqMap[2*x]--;
            }
            
            //if the current element is 0 thecn check whether the frequency of 0 is more than 2 since 2*0 = 0
            if(x == 0 && freqMap[x] > 1){
                //push the element 0 in the original array
                original.push_back(x);
                
                //reduce the frequency twice
                freqMap[x] -= 2;
            }
        }
       //if the 2 x size of created original array is != the the size of changed then return empty {} vector 
       if(n != 2*original.size()){
           return {};
       }
       //else return the original 
       return original;
    }
};