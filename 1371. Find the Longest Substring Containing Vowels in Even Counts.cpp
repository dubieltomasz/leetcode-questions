class Solution {
public:
    int findTheLongestSubstring(const std::string& s) {
        int arr1[32] = {0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
            arr2[26] = {1,0,0,0,2,0,0,0,4,0,0,0,0,0,8,0,0,0,0,0,16,0,0,0,0,0},
            answer = 0, x = 0;

        for(int i = 0; i < s.size(); ++i)
        {
            x ^= arr2[s[i] - 97]; 

            if(arr1[x] == -1) arr1[x] = i+1;
            else answer = std::max(answer, i+1-arr1[x]);
        }

        return answer;
    }
};
