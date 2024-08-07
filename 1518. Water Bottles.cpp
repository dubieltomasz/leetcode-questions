class Solution {
public:
    int numWaterBottles(int numBottles, const int& numExchange) {
        int answer = numBottles;

        while(numBottles >= numExchange)
        {
            answer += numBottles / numExchange;

            numBottles = numBottles / numExchange + numBottles % numExchange;
        }

        return answer;
    }
};
