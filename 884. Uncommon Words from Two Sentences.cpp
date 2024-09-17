class Solution {
public:
    std::vector<std::string> uncommonFromSentences(const std::string& s1, const std::string& s2) {
        std::unordered_map<std::string, int> um;
        std::vector<std::string> answer;
        std::string word;
        std::stringstream s(s1);

        while(s >> word)
            ++um[word];

        s.clear();
        s.str(s2);

        while(s >> word)
            ++um[word];
        
        for(const std::pair<std::string, int>& p : um)
            if(p.second == 1) answer.push_back(p.first);

        return answer;
    }
};
