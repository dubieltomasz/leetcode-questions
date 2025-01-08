class Solution {
public:
    int countPrefixSuffixPairs(const std::vector<std::string>& words) {
        std::vector<std::string> v[50];
        int answer = 0;

        for(int i = 0; i < words.size(); ++i)
        {
            for(int j = 0; j < words[i].size(); ++j)
            {
                for(int k = 0; k < v[j].size(); ++k)
                {
                    if(isPrefixAndSuffix(v[j][k], words[i]))
                        ++answer;
                }
            }

            v[words[i].size()-1].push_back(words[i]);
        }

        return answer;
    }

private:
    bool isPrefixAndSuffix(const std::string& s, const std::string& t)
    {
        int l1 = 0, l2 = 0, r1 = s.size()-1, r2 = t.size()-1;

        while(l1 < s.size() && s[l1] == t[l2] && r1 >= 0 && s[r1] == t[r2])
        {
            ++l1;
            ++l2;
            --r1;
            --r2;
        }
        
        return l1 == s.size() && r1 == -1;
    }
};
