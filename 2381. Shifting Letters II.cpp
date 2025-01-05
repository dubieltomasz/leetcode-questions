class Solution {
public:
    std::string shiftingLetters(std::string& s, const std::vector<std::vector<int>>& shifts) {
        std::vector<int> v(s.size()+1);
        int sum = 0;
        
        for(const std::vector<int>& shift : shifts)
        {
            v[shift[0]] += (shift[2] << 1) - 1;
            v[shift[1]+1] -= (shift[2] << 1) - 1;
        }

        for(int i = 0; i < s.size(); ++i)
        { 
            sum = (sum + v[i]) % 26;
            s[i] = 'a' + (s[i] - 'a' + sum + 26) % 26;
        }
        
        return s;
    }
};
