class Solution {
public:
    std::string addBinary(const std::string& a, const std::string& b) {
        int n = std::max(a.size(), b.size());
        std::string answer(n, '0');
        std::stack<bool> s1, s2;
        bool carry = false;

        for(const char& c : a)
            s1.push(c-'0');

        for(const char& c : b)
            s2.push(c-'0');
        
        while(!s1.empty() && !s2.empty())
        {
            answer[--n] = (carry ^ s1.top() ^ s2.top()) + '0';
            carry = s1.top() & s2.top() | (s1.top() ^ s2.top()) & carry;
            s1.pop();
            s2.pop();
        }

        while(!s1.empty())
        {
            answer[--n] = (carry ^ s1.top()) + '0';
            carry &= s1.top();
            s1.pop();
        }
        
        while(!s2.empty())
        {
            answer[--n] = (carry ^ s2.top()) + '0';
            carry &= s2.top();
            s2.pop();
        }

        return carry ? "1" + answer : answer;
    }
};
