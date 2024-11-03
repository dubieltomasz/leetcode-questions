class Solution {
public:
    bool rotateString(std::string& s, const std::string& goal) {
        int i = 0;

        while(i < s.size())
        {
            if(s == goal) break;

            s.push_back(s.front());
            s.erase(s.begin());

            ++i;
        }

        return i != s.size();
    }
};
