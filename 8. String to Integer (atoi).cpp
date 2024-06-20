class Solution {
public:
    int myAtoi(const string& s) {
        int answer = 0;
        int i = 0;

        while(s[i] == ' ')
            ++i;

        if(s[i] == '-')
        {
            ++i;

            while(i < s.size() && int(s[i]) > 47 && int(s[i]) < 58)
            {
                if(answer < (INT_MIN+(int(s[i])-48))/10) return INT_MIN;

                answer = answer * 10 - (int(s[i])-48);
                ++i;
            }

            return answer;
        }
        else if(s[i] == '+')
        {
            ++i;
        }

        while(i < s.size() && int(s[i]) > 47 && int(s[i]) < 58)
        {
            if(answer > (INT_MAX-(int(s[i])-48))/10) return INT_MAX;

            answer = answer * 10 + (int(s[i])-48);
            ++i;
        }

        return answer;
    }
};
