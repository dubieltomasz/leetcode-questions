class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int answer = 0;

        for(int y = 0; y < grid2.size(); ++y)
        {
            for(int x = 0; x < grid2[0].size(); ++x)
            {
                if(grid2[y][x])
                {
                    ok = true;
                    func(grid1, grid2, y, x);
                    answer += ok;
                }
            }
        }

        return answer;
    }

private:
    bool ok;

    void func(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int y, int x)
    {
        if(y < 0 || y == grid2.size() || x < 0 || x == grid2[0].size() || grid2[y][x] == 0) return;

        grid2[y][x] = 0;

        if(grid1[y][x] == 0) ok = false;

        func(grid1, grid2, y+1, x);
        func(grid1, grid2, y, x+1);
        func(grid1, grid2, y-1, x);
        func(grid1, grid2, y, x-1);
    }
};
