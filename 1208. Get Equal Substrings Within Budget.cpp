class Solution {
public:
    int equalSubstring(const string& s, const string& t, const int& maxCost) {
        int answer = 0;
        int tmp1 = 0;

        for(int i = 0, j = 0; i < s.size() && j < s.size(); ++i)
        {
            while(j < s.size() && abs(int(t[j]) - int(s[j])) <= maxCost - tmp1)
                tmp1 += abs(int(t[j]) - int(s[j++]));

            answer = max(answer, j-i);

            tmp1 -= abs(int(t[i]) - int(s[i]));
        }

        return answer; 
    }
};
