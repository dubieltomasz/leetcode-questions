class Solution {
public:
    std::string addSpaces(const std::string& s, const std::vector<int>& spaces) {
        std::string answer = "";
        int i = 0;

        for(int j = 0; j < spaces.size();)
        {
            if(i == spaces[j])
            {
                answer += ' ';
                ++j;
            }

            answer += s[i++];
        }

        return answer + s.substr(i, s.size()-i);
    }
};
