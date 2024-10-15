class Solution {
public:
    long long minimumSteps(const std::string& s) {
        long long answer = 0;
        int b = s.size()-1;

        for(int i = s.size()-1; i >= 0; --i)
        {
            switch(s[i])
            {
                case '1':
                    answer += b-i;
                    --b;
            }
        }

        return answer;
    }
};
