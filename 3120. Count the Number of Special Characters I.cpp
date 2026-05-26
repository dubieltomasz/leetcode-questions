class Solution {
public:
    int numberOfSpecialChars(const std::string& word) {
        std::array<bool, 'z' - 'A' + 1> arr{};
        int sum = 0;

        for(const auto& character : word) {
            arr[character - 'A'] = true;
        }

        for(int i = 0; i <= 'z' - 'a'; ++i) {
            sum += arr[i] && arr[i + 'a' - 'A'];
        }

        return sum;
    }
};
