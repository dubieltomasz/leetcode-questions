class Solution {
public:
    std::string numberToWords(int num) {
        if(!num) return "Zero";

        int x = 0, tmp;
        std::string answer = "";
        
        const std::string convert0_19[20] =
        {
            "",
            "One ",       "Two ",      "Three ",
            "Four ",      "Five ",     "Six ",
            "Seven ",     "Eight ",    "Nine ",
            "Ten ",
            "Eleven ",    "Twelve ",   "Thirteen ",
            "Fourteen ",  "Fifteen ",  "Sixteen ",
            "Seventeen ", "Eighteen ", "Nineteen "
        },
        convert10s[10] =
        {
            "",
            "",         "Twenty ", "Thirty ",
            "Forty ",   "Fifty ",  "Sixty ",
            "Seventy ", "Eighty ", "Ninety "
        },
        convertBig[4] =
        {
            "",
            "Thousand ",
            "Million ",
            "Billion "
        };

        while(num)
        {
            if(num % 1000) answer = convertBig[x] + answer;

            tmp = num % 100;
            num /= 100;

            if(tmp < 20) answer = convert0_19[tmp] + answer;
            else
            {
                answer = convert0_19[tmp % 10] + answer;
                tmp /= 10;
                answer = convert10s[tmp] + answer;
            }

            tmp = num % 10;
            num /= 10;
            if(tmp) answer = convert0_19[tmp % 10] + "Hundred " + answer;

            ++x;
        }

        return answer.substr(0, answer.size()-1);
    }
};
