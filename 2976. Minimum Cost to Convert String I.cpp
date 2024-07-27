class Solution {
public:
    long long minimumCost(const std::string& source, const std::string& target, const std::vector<char>& original, const std::vector<char>& changed, const std::vector<int>& cost) {
        std::vector<std::vector<int>> changeMatrix (26, std::vector<int> (26, 1e9));
        long long answer = 0;
        int add;

        for(int i = 0; i < original.size(); ++i)
            changeMatrix[int(original[i])-'a'][int(changed[i])-'a'] = std::min(cost[i], changeMatrix[int(original[i])-'a'][int(changed[i])-'a']);
        
        for(int i = 0; i < 26; ++i)
            changeMatrix[i][i] = 0;
        
        for(int k = 0; k < 26; ++k)
        {
            for(int i = 0; i < 26; ++i)
            {
                for(int j = 0; j < 26; ++j)
                {
                    changeMatrix[i][j] = std::min(changeMatrix[i][j], changeMatrix[i][k] + changeMatrix[k][j]);
                }
            }
        }

        for(int i = 0; i < source.size(); ++i)
        {
            add = changeMatrix[int(source[i])-'a'][int(target[i])-'a'];

            if(add == 1e9) return -1;
            else answer += add;
        }

        return answer;
    }
};
