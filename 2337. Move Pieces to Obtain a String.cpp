class Solution {
public:
    bool canChange(const std::string& start, const std::string& target) {
        int n = start.length(), arr[20] = {};

        for(int i = 0; i < n; ++i)
        {
            ++arr[start[i]-76];
            --arr[target[i]-76];

            if(arr[0] > 0 || arr[6] < 0 || arr[6] && start[i] == 'L' || arr[0] && arr[6])
                return false;
        }

        return !arr[0] && !arr[6];
    }
};
