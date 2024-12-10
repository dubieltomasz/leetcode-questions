class Solution {
public:
    int maximumLength(const std::string& s) {
        int n = s.size(), answer = -1, start = 0, end = 0, count;
        std::vector<std::vector<int>> v3(26, std::vector<int> (n));

        while(end <= n)
        {
            while(end < n && s[start] == s[end])
                ++end;
            
            count = 1;

            for(int len = end-start-1; len > answer && count <= 3; --len)
            {
                v3[s[start]-97][len] += count++;

                if(v3[s[start]-97][len] >= 3)
                {
                    answer = len;
                    break;
                }
            }

            start = end++;
        }
        
        return answer+1 ? answer+1 : -1;
    }
};
