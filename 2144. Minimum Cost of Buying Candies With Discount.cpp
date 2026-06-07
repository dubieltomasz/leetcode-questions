class Solution {
public:
    int minimumCost(std::vector<int>& cost) {
        std::ranges::sort(cost, std::greater<int>());

        int sum = 0;

        size_t i = 0;
        while(i < cost.size() - 1) {
            sum += cost[i] + cost[i + 1];
            i += 3;
        }

        if(i < cost.size()) {
            sum += cost[i];
        }

        return sum;
    }
};
