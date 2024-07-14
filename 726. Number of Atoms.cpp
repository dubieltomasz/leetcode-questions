class Solution {
public:
    std::string countOfAtoms(const std::string& formula) {
        std::map<std::string, int> m = mapOfAtoms(formula);
        std::string answer = "";

        for(const std::pair<std::string, int>& p : m)
        {
            answer += p.first;
            
            if(p.second > 1) answer += to_string(p.second);
        }

        return answer;
    }

private:
    std::map<std::string, int> mapOfAtoms(const std::string& formula)
    {
        std::map<std::string, int> m;
        std::string answer = "", currentAtom;
        int amount, n, j;

        for(int i = 0; i < formula.size();)
        {
            amount = 0;

            if(formula[i] == '(')
            {
                n = 1, j = i+1;

                while(n)
                {
                    if(formula[j] == '(') ++n;
                    else if(formula[j] == ')') --n;
                    
                    ++j;
                }

                std::map<std::string, int> m1 = mapOfAtoms(formula.substr(i+1, j-i-2));
                
                i = j;

                while('0' <= formula[i] && formula[i] <= '9')
                {
                    amount = amount * 10 + int(formula[i])-48;
                    ++i;
                }

                amount = max(amount, 1);

                for(const std::pair<std::string, int>& p : m1)
                    m[p.first] += p.second * amount;
            }
            else
            {
                currentAtom = formula[i++];

                if('a' <= formula[i] && formula[i] <= 'z')
                {
                    currentAtom += formula[i];
                    ++i;
                }

                while('0' <= formula[i] && formula[i] <= '9')
                {
                    amount = amount * 10 + int(formula[i])-48;
                    ++i;
                }

                m[currentAtom] += std::max(amount, 1);
            }
        }

        return m;
    }
};
