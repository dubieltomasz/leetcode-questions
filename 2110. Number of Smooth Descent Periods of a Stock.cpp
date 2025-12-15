class Solution {
public:
    long long getDescentPeriods(const std::vector<int>& prices) {
        long long answer = 0, number = 1;

        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i - 1] - prices[i] == 1) {
                ++number;
            } else {
                answer += (number * (number + 1)) >> 1;
                number = 1;
            }
        }
        answer += (number * (number + 1)) >> 1;

        return answer;
    }
};
