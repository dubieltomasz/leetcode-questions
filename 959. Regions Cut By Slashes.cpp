class Solution {
public:
    int regionsBySlashes(const std::vector<std::string>& grid) {
        int n = grid.size(), answer = 0;
        N = n*3;
        std::vector<std::vector<int>> v(N, std::vector<int>(N));

        for(int i = 0, I = 0; i < n; ++i, I += 3)
        {
            for(int j = 0, J = 0; j < n; ++j, J += 3)
            {
                switch(grid[i][j])
                {
                    case '/':
                        v[I]  [J+2] = 1;
                        v[I+1][J+1] = 1;
                        v[I+2][J]   = 1;
                        break;
                    case '\\':
                        v[I]  [J]   = 1;
                        v[I+1][J+1] = 1;
                        v[I+2][J+2] = 1;
                        break;
                }
            }
        }

        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                if(!v[i][j])
                {
                    ++answer;

                    func(v, i, j);
                }
            }
        }

        return answer;
    }

private:
    int N;

    void func(std::vector<std::vector<int>>& v, int i, int j)
    {
        if(v[i][j]) return;

        v[i][j] = 1;

        if(i > 0)   func(v, i-1, j);
        if(i < N-1) func(v, i+1, j);
        if(j > 0)   func(v, i,   j-1);
        if(j < N-1) func(v, i,   j+1);
    }
};
