class Solution {
public:
    std::string kthDistinct(const std::vector<std::string>& arr, int k) {
        std::unordered_map<std::string, int> um;

        for(const std::string& element : arr)
            ++um[element];
        
        for(const std::string& element : arr)
            if(um[element] == 1 && !--k) return element;

        return "";
    }
};
