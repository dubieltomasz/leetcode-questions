class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unsigned int i = 0;

        for(int n = 0; ++n <= arr.size()/4; ++i)
            if(arr[i] != arr[i+1]) n = 0;

        return arr[i];
    }
};
