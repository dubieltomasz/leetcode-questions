class Solution {
public:
    std::vector<std::vector<int>> spiralMatrixIII(const int rows, const int cols, int rStart, int cStart) {
        int j = 1, c = rows*cols;
        std::vector<std::vector<int>> answer;
        answer.reserve(c);

        answer.push_back({rStart, cStart});
        --c;

        while(c)
        {
            for(int i = 0; i < j; ++i)
            {
                ++cStart;

                if(rStart >= 0 && cStart >= 0 && rStart < rows && cStart < cols)
                {
                    answer.push_back({rStart, cStart});
                    --c;
                }
            }

            for(int i = 0; i < j; ++i)
            {
                ++rStart;

                if(rStart >= 0 && cStart >= 0 && rStart < rows && cStart < cols)
                {
                    answer.push_back({rStart, cStart});
                    --c;
                }
            }

            ++j;
            
            for(int i = 0; i < j; ++i)
            {
                --cStart;

                if(rStart >= 0 && cStart >= 0 && rStart < rows && cStart < cols)
                {
                    answer.push_back({rStart, cStart});
                    --c;
                }
            }

            for(int i = 0; i < j; ++i)
            {
                --rStart;

                if(rStart >= 0 && cStart >= 0 && rStart < rows && cStart < cols)
                {
                    answer.push_back({rStart, cStart});
                    --c;
                }
            }

            ++j;
        }

        return answer;
    }
};
