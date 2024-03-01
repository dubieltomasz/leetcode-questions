class Solution {
public:
    string maximumOddBinaryNumber(const string& s) {
        string answer = "";
        answer.reserve(answer.size());

        int ones = 0, zeros = 0;
        for(const char& c : s)
            if(c == '1') ++ones;
            else ++zeros;

        while(--ones > 0)
            answer += "1";

        while(zeros-- > 0)
            answer += "0";

        return answer + "1";
    }
};
