class Solution {
public:
    long long maxMatrixSum(const std::vector<std::vector<int>>& matrix) {
        int minVal = INT_MAX, countNegatives = 0;
        long long answer = 0;
        
        for(const std::vector<int>& row : matrix)
        {
            for(const int& cell : row)
            {
                if(cell < 0) ++countNegatives;

                minVal = std::min(minVal, std::abs(cell));
                answer += std::abs(cell);
            }
        }

        return countNegatives & 1 ? answer - (minVal << 1) : answer;
    }
};
