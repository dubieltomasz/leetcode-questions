class Solution {
public:
    string convert(const string& s, const int& numRows) {
        if(numRows == 1) return s;

        string answer = "";
        vector<string> v(numRows);        

        for(int i = 0; i < s.size();)
        {
            int j = 0;

            while(j < numRows && i < s.size())
            {
                v[j].push_back(s[i]);

                ++i;
                ++j;
            }

            j -= 2;

            while(j > 0 && i < s.size())
            {
                v[j].push_back(s[i]);

                ++i;
                --j;
            }
        }

        for(const string& s : v)
            answer += s;

        return answer;
    }
};
