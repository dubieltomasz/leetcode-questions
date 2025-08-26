class Solution {
public:
    int totalFruit(const std::vector<int>& fruits) {
        int left = 0, right = 0, distinctFruits = 0, maxFruits = 0;
        std::vector<int> typesOfFruits(fruits.size());

        while(right < fruits.size()){
            if(++typesOfFruits[fruits[right++]] == 1){
                ++distinctFruits;
            }

            maxFruits = std::max(maxFruits, right - left - 1);
            
            while(distinctFruits == 3){
                if(--typesOfFruits[fruits[left++]] == 0){
                    --distinctFruits;
                }
            }
        }

        return std::max(maxFruits, right - left);
    }
};
