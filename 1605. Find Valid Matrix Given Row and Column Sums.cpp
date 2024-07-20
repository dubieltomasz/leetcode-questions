class Solution {
public:
    std::vector<std::vector<int>> restoreMatrix(std::vector<int>& rowSum, std::vector<int>& colSum)
    {
        std::vector<std::vector<int>> answer (rowSum.size(), std::vector<int> (colSum.size()));

        for(int i = 0; i < rowSum.size(); ++i)
        {
            for(int j = 0; j < colSum.size() && rowSum[i]; ++j)
            {
                rowSum[i] -= answer[i][j] = std::min(rowSum[i], colSum[j]);
                colSum[j] -= answer[i][j];
            }
        }

        return answer;    
    }
};
