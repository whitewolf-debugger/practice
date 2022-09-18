class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0 , index = 0 , n = height.size();
        stack<int> st;
        while(index < n){
            while(!st.empty() && height[index] > height[st.top()]){
                int top = st.top();
                st.pop();
                if(st.empty()) break;
                int distance = index - st.top() - 1;
                int height_bound = min(height[index],height[st.top()]) - height[top];
                ans += distance * height_bound;
            }
            st.push(index++);
        }
        return ans;
    }
};
/*
   0   1   0   2   1   0   1   3   2   1   2   1

   |         |    
   |         |  index =  2
   |         |
   |         |
   |____1____|
   |____0____|

 now  after poping the top element

  0   1   0   2   1   0   1   3   2   1   2   1

   |         |    
   |         |  index =  2
   |         |  top = 1
   |         |  st.top() = 0            2           1                   0
   |         |  height_bound = min(height[index],height[st.top()]) - height[top]; = 1
   |____0____|  distance = index - st.top() - 1; = 1
                area = distance * height_bound;




*/