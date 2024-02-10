
class Solution {
public:
    int countSubstrings(const string& s) {
        int answer = 0;

        for(size_t i = 0; i < s.size(); ++i)
        {
            for(int left = i, right = i; left >= 0 && right < s.size() && s[left] == s[right]; --left, ++right)
                ++answer;

            for(int left = i, right = i+1; left >= 0 && right < s.size() && s[left] == s[right]; --left, ++right)
                ++answer;
        }

        return answer;
    }
};
