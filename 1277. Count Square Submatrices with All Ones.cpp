class Solution {
public:
    int countSquares(const std::vector<std::vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), answer = 0;
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1));

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j])
                {
                    answer += dp[i+1][j+1] = std::min({dp[i][j], dp[i][j+1], dp[i+1][j]}) + 1;
                }
            }
        }

        return answer;
    }
};
