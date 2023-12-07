class Solution {
public:
    string largestOddNumber(string num) {
        char *end = &num[num.length()-1];

        while(end >= &num[0] && (int(*end)-48) % 2 == 0)
            --end;

        return num.erase(num.find_last_not_of(++end)+1);
    }
};
