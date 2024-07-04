class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int answer = 0;
        
        for(int y = 0; y < grid.size(); ++y)
            for(int x = 0; x < grid[0].size(); ++x)
                if(grid[y][x]) answer = std::max(answer, area(grid, y, x));

        return answer;
    }

private:
    int area(vector<vector<int>>& grid, const int& y, const int& x)
    {
        if(y < 0 || x < 0 || y == grid.size() || x == grid[0].size() || !grid[y][x]) return 0;
        else
        {
            grid[y][x] = 0;
            return 1 + area(grid, y+1, x) + area(grid, y, x+1) + area(grid, y-1, x) + area(grid, y, x-1);
        }
    }
};
