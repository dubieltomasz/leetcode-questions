class Solution {
public:
    int maxMoves(std::vector<std::vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), i = 0;
        bool ok = true;
        
        grid.insert(grid.begin(), vector<int>(n, 1000000));
        grid.push_back(vector<int>(n, 1000000));

        while(ok && ++i < n)
        {
            ok = false;

            for(int j = 1; j < m+1; ++j)
            {
                if(std::min({grid[j-1][i-1], grid[j][i-1], grid[j+1][i-1]}) >= grid[j][i])
                    grid[j][i] = 1000000;
                else ok = true;
            }
        }

        return i-1;
    }
};
