class Solution {
public:
    int prefixCount(const std::vector<std::string>& words, const std::string& pref) {
        int answer = 0, n = pref.size();

        for(const std::string& word : words)
        {
            if(word.size() >= n)
            {
                int i = 0;
                
                while(i < n)
                {
                    if(word[i] != pref[i])
                        break;

                    ++i;
                }

                if(i == n) ++answer;
            }
        }

        return answer;
    }
};
