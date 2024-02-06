class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;

        for(const string& str : strs)
        {
            string tmpS = str;
            ranges::sort(tmpS);
            
            um[tmpS].push_back(str);
        }

        vector<vector<string>> answer{};

        for(const auto& [_, elem] : um)
            answer.push_back(elem);

        return answer;
    }
};
