class Solution {
public:
    std::vector<std::string> sortPeople(std::vector<std::string>& names, const std::vector<int>& heights) {
        std::vector<std::pair<std::string, int>> v(names.size());
        
        for(int i = 0; i < names.size(); ++i)
            v[i] = {names[i], heights[i]};
        
        std::sort(v.begin(), v.end(), [&](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) -> bool { return a.second > b.second; });

        int i = 0;
        for(const std::pair<std::string, int>& p : v)
            names[i++] = p.first;

        return names;
    }
};
