class Solution {
public:
    int countUnguarded(const int m, const int n, const std::vector<std::vector<int>>& guards, const std::vector<std::vector<int>>& walls) {
        std::vector<std::vector<int>> grid(m, std::vector<int>(n, 1));
        int answer = 0;

        for(const std::vector<int>& wall : walls)
            grid[wall[0]][wall[1]] = 0;

        for(const std::vector<int>& guard : guards)
        {
            for(int i = guard[0]-1; i >= 0 && grid[i][guard[1]] != -1 && grid[i][guard[1]] != 0; --i)
                grid[i][guard[1]] = -1;

            for(int i = guard[0]+1; i < m && grid[i][guard[1]] != -1 && grid[i][guard[1]] != 0; ++i)
                grid[i][guard[1]] = -1;

            for(int i = guard[1]-1; i >= 0 && grid[guard[0]][i] != -2 && grid[guard[0]][i] != 0; --i)
                grid[guard[0]][i] = -2;

            for(int i = guard[1]+1; i < n && grid[guard[0]][i] != -2 && grid[guard[0]][i] != 0; ++i)
                grid[guard[0]][i] = -2;
            
            grid[guard[0]][guard[1]] = 0;
        }

        for(const std::vector<int>& row : grid)
            for(const int& cell : row)
                if(cell == 1) ++answer;

        return answer;
    }
};
