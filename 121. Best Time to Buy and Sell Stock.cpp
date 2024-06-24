class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int maxVal = prices.back(), answer = 0;

        for(int i = prices.size()-2; i > -1; --i)
        {
            maxVal = max(maxVal, prices[i]);
            answer = max(answer, maxVal-prices[i]);
        }

        return answer;
    }
};
