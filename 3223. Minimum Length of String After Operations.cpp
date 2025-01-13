class Solution {
public:
    int minimumLength(const std::string& s) {
        int2_t arr[26] = {};
        int answer = 0;

        for(const char& c : s)
        {
            arr[c-'a'].value |= 2;
            arr[c-'a'].value ^= 1;
        }

        for(int i = 0; i < 26; ++i)
            answer += (arr[i].value & 2) - (arr[i].value & 1);

        return answer;
    }

private:
    struct int2_t{
        unsigned value : 2;
    };
};
