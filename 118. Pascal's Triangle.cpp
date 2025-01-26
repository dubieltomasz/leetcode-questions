class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> answer(numRows, {1});
        int idx = 1;

        while(--numRows)
        {
            for(int i = 1; i < answer[idx-1].size(); ++i)
                answer[idx].push_back(answer[idx-1][i-1] + answer[idx-1][i]);

            answer[idx].push_back(1);
            
            ++idx;
        }

        return answer;
    }
};
