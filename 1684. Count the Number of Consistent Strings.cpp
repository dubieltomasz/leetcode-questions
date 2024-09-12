class Solution {
public:
    int countConsistentStrings(const std::string& allowed, const std::vector<std::string>& words) {
        bool arrOfAllowed[26] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, ok;
        int answer = 0;

        for(const char& c : allowed)
            arrOfAllowed[c-97] = 0;

        for(const std::string& word : words)
        {
            ok = true;

            for(const char& c : word)
                if(arrOfAllowed[c-97]) ok = false;

            if(ok) ++answer;
        }
            
        return answer;
    }
};
