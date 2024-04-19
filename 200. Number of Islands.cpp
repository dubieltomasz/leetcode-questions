class Solution {
private:
    void toStars(vector<vector<char>>& grid, const size_t& m, const size_t& n, const int& i, const int& j)
    {
        grid[i][j] = '#';

        if(i+1 < m && grid[i+1][j] == '1') toStars(grid, m, n, i+1, j);
        if(j+1 < n && grid[i][j+1] == '1') toStars(grid, m, n, i, j+1);
        if(i-1 > -1 && grid[i-1][j] == '1') toStars(grid, m, n, i-1, j);
        if(j-1 > -1 && grid[i][j-1] == '1') toStars(grid, m, n, i, j-1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        size_t m = grid.size(), n = grid[0].size();
        int answer = 0;

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(grid[i][j] == '1')
                {
                    ++answer;
                    toStars(grid, m, n, i, j);
                }

        return answer;
    }
};
