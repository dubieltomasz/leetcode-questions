class Solution {
public:
    std::vector<std::string> stringMatching(const std::vector<std::string>& words) {
        std::vector<std::string> answer;
        bool x;
        
        for(int i = 0; i < words.size(); ++i)
        {
            x = true;

            for(int j = 0; x && j < i; ++j)
            {
                if(words[i].size() < words[j].size() && words[j].find(words[i]) < words[j].size())
                {
                    answer.push_back(words[i]);
                    x = false;
                }
            }

            for(int j = i+1; x && j < words.size(); ++j)
            {
                if(words[i].size() < words[j].size() && words[j].find(words[i]) < words[j].size())
                {
                    answer.push_back(words[i]);
                    break;
                }
            }
        }

        return answer;
    }
};
