class Solution {
public:
    int numSteps(string& s) {
        int answer = 0;

        int i = s.size()-1;

        while(i > 0)
        {
            if(s[i] == '0')
            {
                ++answer;
                --i;
            }
            else
            {
                int j = i;
                ++answer;

                while(j > 0 && s[j] == '1')
                {
                    s[j] = '0';
                    --j;
                }

                s[j] ^= '0';
                s[j] ^= '1';
            }
        }

        return (s[0] == '0') ? answer+1 : answer;
    }
};
