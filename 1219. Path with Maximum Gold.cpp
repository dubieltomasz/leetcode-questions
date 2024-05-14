class Solution {
private:
    int answer = 0, m, n;

    void func(vector<vector<int>>& grid, const int& i, const int& j, int gold)
    {
        gold += grid[i][j];
        int tmp = grid[i][j];
        grid[i][j] = 0;

        answer = max(answer, gold);

        if(i > 0 && grid[i-1][j] != 0) func(grid, i-1, j, gold);
        if(j < n-1 && grid[i][j+1] != 0) func(grid, i, j+1, gold);
        if(i < m-1 && grid[i+1][j] != 0) func(grid, i+1, j, gold);
        if(j > 0 && grid[i][j-1] != 0) func(grid, i, j-1, gold);

        grid[i][j] = tmp;
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(grid[i][j] != 0) func(grid, i, j, 0);

        return answer;
    }
};
