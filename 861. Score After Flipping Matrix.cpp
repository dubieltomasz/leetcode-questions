class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), answer = 0, tmp;

        for(vector<int>& row : grid) if(!row[0])
        {
            for(int& elem : row)
            {
                elem ^= 0;
                elem ^= 1;
            }
        }

        for(int i = 0; i < n; ++i)
        {
            tmp = 0;

            for(int j = 0; j < m; ++j)
                tmp += grid[j][i];

            if(tmp < m - tmp) for(int j = 0; j < m; ++j)
            {
                grid[j][i] ^= 0;
                grid[j][i] ^= 1;
            }
        }

        for(const vector<int>& row : grid)
        {
            tmp = 0;

            for(const int& elem : row)
            {
                tmp <<= 1;
                tmp += elem;
            }

            answer += tmp;
        }

        return answer;
    }
};
