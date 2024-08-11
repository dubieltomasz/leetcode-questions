class Solution {
public:
    int minDays(std::vector<std::vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if(countIslands(grid) != 1) return 0;

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j])
                {
                    grid[i][j] = 0;

                    if(countIslands(grid) != 1) return 1;

                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }

private:
    int m, n;

    int countIslands(std::vector<std::vector<int>> grid)
    {
        int count = 0;

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j])
                {
                    ++count;

                    func(grid, i, j);
                }
            }
        }

        return count;
    }

    void func(std::vector<std::vector<int>>& grid, int i, int j)
    {
        if(!grid[i][j]) return;

        grid[i][j] = 0;

        if(i > 0)   func(grid, i-1, j);
        if(j > 0)   func(grid, i,   j-1);
        if(i < m-1) func(grid, i+1, j);
        if(j < n-1) func(grid, i,   j+1);
    }
};
