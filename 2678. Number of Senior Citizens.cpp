class Solution {
public:
    int countSeniors(const std::vector<std::string>& details) {
        int count = 0;

        for(const std::string& data : details)
            if(data[11] > 54 || data[11] == 54 && data[12] > 48) ++count;

        return count;
    }
};
