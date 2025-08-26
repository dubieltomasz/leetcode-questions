class Solution {
public:
    int numOfUnplacedFruits(const std::vector<int>& fruits, std::vector<int>& baskets) {
        int unplacedFruits = 0;

        for(const int& fruit : fruits){
            for(int& basket : baskets){
                if(basket >= fruit){
                    basket = 0;
                    goto next;
                }
            }

            ++unplacedFruits;
            next:
        }
    
        return unplacedFruits;
    }
};
