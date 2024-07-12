class Solution {
public:
    int maximumGain(const std::string& s, int x, int y) {
        int answer = 0, c1count = 0, c2count = 0;
        char c1 = 'a', c2 = 'b';

        if(x < y)
        {
            c1 = 'b';
            c2 = 'a';
            std::swap(x, y);
        }

        for(const char& c : s)
        {
            if(c == c1) ++c1count;
            else if(c == c2)
            {
                if(c1count > 0)
                {
                    answer += x;
                    --c1count;
                }
                else ++c2count;
            }
            else
            {
                answer += y * min(c1count, c2count);

                c1count = 0;
                c2count = 0;
            }
        }

        answer += y * min(c1count, c2count);

        return answer;
    }
};
