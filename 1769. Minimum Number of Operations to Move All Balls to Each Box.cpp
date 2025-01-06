class Solution {
public:
    std::vector<int> minOperations(const std::string& boxes) {
        std::vector<int> answer(boxes.size());
        int countBalls = 0, moves = 0;

        for(int i = 0; i < boxes.size(); ++i)
        {
            answer[i] += moves;

            countBalls += (boxes[i] == '1');

            moves += countBalls;
        }

        moves = 0;
        countBalls = 0;

        for(int i = boxes.size()-1; i >= 0; --i)
        {
            answer[i] += moves;

            countBalls += (boxes[i] == '1');

            moves += countBalls;
        }

        return answer;
    }
};
