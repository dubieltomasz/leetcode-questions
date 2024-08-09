class Solution {
public:
    int numMagicSquaresInside(const std::vector<std::vector<int>>& grid) {
        if(grid.size() == 0) return 0;

        int row = grid.size(), col = grid[0].size(), answer = 0;

        for(int i = 1; i < row-1; ++i)
        {
            for(int j = 1; j < col-1; ++j)
            {
                if(checkGrid(grid, i, j))
                    ++answer;
            }
        }

        return answer;
    }

private:
    bool checkGrid(const std::vector<std::vector<int>>& grid, const int i, const int j)
    {
        int arr[10] = {0,0,0,0,0,0,0,0,0,0};

        for(int I = i-1; I < i+2; ++I)
        {
            for(int J = j-1; J < j+2; ++J)
            {
                if(grid[I][J] < 1 || grid[I][J] > 9 || arr[grid[I][J]] > 0)
                    return false;
                else
                    ++arr[grid[I][J]];
            }
        }

        int d1S = grid[i-1][j-1] + grid[i][j] + grid[i+1][j+1];
        int d2S = grid[i-1][j+1] + grid[i][j] + grid[i+1][j-1];

        int r1S = grid[i-1][j-1] + grid[i-1][j] + grid[i-1][j+1];
        int r2S = grid[i][j-1]   + grid[i][j]   + grid[i][j+1];
        int r3S = grid[i+1][j-1] + grid[i+1][j] + grid[i+1][j+1];

        int c1S = grid[i-1][j-1] + grid[i][j-1] + grid[i+1][j-1];
        int c2S = grid[i-1][j]   + grid[i][j]   + grid[i+1][j];
        int c3S = grid[i-1][j+1] + grid[i][j+1] + grid[i+1][j+1];

        if(
            d1S != d2S ||
            d1S != r1S ||
            d1S != r2S ||
            d1S != r3S ||
            d1S != c1S ||
            d1S != c2S ||
            d1S != c3S
          )
            return false;

        return true;
    }
};
