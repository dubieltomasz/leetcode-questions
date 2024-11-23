class Solution {
public:
    std::vector<std::vector<char>> rotateTheBox(const std::vector<std::vector<char>>& box) {
        int n = box.size(), m = box[0].size(), countStones = 0, k;
        std::vector<std::vector<char>> answer(m, std::vector<char>(n, '.'));

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(box[i][j] == '#')
                {
                    ++countStones;
                }
                else if(box[i][j] == '*')
                {
                    answer[j][n-i-1] = '*';
                    k = 1;

                    while(countStones)
                    {
                        answer[j-k][n-i-1] = '#';
                        --countStones;
                        ++k;
                    }
                }
            }

            k = 1;

            while(countStones)
            {
                answer[m-k][n-i-1] = '#';
                --countStones;
                ++k;
            }
        }

        return answer;
    }
};
