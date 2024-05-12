class Solution {
public:
    vector<vector<int>> largestLocal(const vector<vector<int>>& grid) {
        int N = grid.size(), n = grid[0].size();
        vector<vector<int>> answer(N-2, vector<int>(n-2));

        for(int I = 1; I < N-1; ++I)
        {
            for(int J = 1; J < n-1; ++J)
            {
                for(int i = -1; i < 2; ++i)
                {
                    for(int j = -1; j < 2; ++j)
                    {
                        answer[I-1][J-1] = std::max(answer[I-1][J-1], grid[I+i][J+j]);
                    }
                }
            }
        }

        return answer;
    }
};
