class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int , int> basket;
        int windowStart= 0 ,windowEnd;
        for( windowEnd = 0; windowEnd < fruits.size();windowEnd++) {
            basket[fruits[windowEnd]]++;
            if(basket.size() > 2 && windowStart < fruits.size()) {
                basket[fruits[windowStart]]--;
                if(basket[fruits[windowStart]] == 0) {
                    basket.erase(fruits[windowStart]);
                }
                windowStart++;
            }
        }

        return windowEnd - windowStart;
    }
};