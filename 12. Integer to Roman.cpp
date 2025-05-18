class Solution {
public:
    std::string intToRoman(int num) {
        std::string answer = "";

        while(num >= 1000)
        {
            answer += 'M';
            num -= 1000;
        }

        if(num >= 900)
        {
            answer += "CM";
            num -= 900;
        }

        if(num >= 500)
        {
            answer += 'D';
            num -= 500;
        }
        else if(num >= 400)
        {
            answer += "CD";
            num -= 400;
        }
        
        while(num >= 100)
        {
            answer += 'C';
            num -= 100;
        }

        if(num >= 90)
        {
            answer += "XC";
            num -= 90;
        }
        
        if(num >= 50)
        {
            answer += 'L';
            num -= 50;
        }
        else if(num >= 40)
        {
            answer += "XL";
            num -= 40;
        }
        
        while(num >= 10)
        {
            answer += 'X';
            num -= 10;
        }
        
        if(num >= 9)
        {
            answer += "IX";
            num -= 9;
        }
        
        if(num >= 5)
        {
            answer += 'V';
            num -= 5;
        }
        else if(num >= 4)
        {
            answer += "IV";
            num -= 4;
        }

        while(num > 0)
        {
            answer += 'I';
            --num;
        }

        return answer;
    }
};
