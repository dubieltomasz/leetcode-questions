class Solution {
private:
    short func(const char& character)
    {
        switch(character)
        {
            case 'I':
                return 1;
                break;
            case 'V':
                return 5;
                break;
            case 'X':
                return 10;
                break;
            case 'L':
                return 50;
                break;
            case 'C':
                return 100;
                break;
            case 'D':
                return 500;
                break;
            default: //'M'
                return 1000;
                break;
        }
    }

public:
    int romanToInt(const string& s) {
        int answer = 0;

        for(size_t i = 0; i < s.size()-1; ++i)
        {
            if(func(s[i]) < func(s[i+1])) answer -= func(s[i]);
            else answer += func(s[i]);
        }

        return answer + func(s[s.size()-1]);
    }
};
