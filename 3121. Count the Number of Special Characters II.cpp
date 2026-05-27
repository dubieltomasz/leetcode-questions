class Solution {
public:
    int numberOfSpecialChars(const std::string& word) {
        constexpr size_t n = 'z' - 'a' + 1;
        constexpr uint8_t lowercaseExists = 0b100, uppercaseExists = 0b010, valid = 0b110;
        std::array<uint8_t, n> flagArray{};
        int sum = 0;

        for(const char& character : word) {
            if(character > 'Z') {
                auto& flags = flagArray[character - 'a'];
                flags |= lowercaseExists;
                flags |= (flags & uppercaseExists) >> 1;
            } else {
                auto& flags = flagArray[character - 'A'];
                flags |= uppercaseExists;
                flags |= !(flags & lowercaseExists);
            }
        }

        for(const uint8_t& flags : flagArray) {
            sum += flags == valid;
        }

        return sum;
    }
};
