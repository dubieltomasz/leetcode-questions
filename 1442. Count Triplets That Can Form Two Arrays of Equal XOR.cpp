class Solution {
public:
    int countTriplets(vector<int>& arr)
    {
        int answer = 0;
        arr.insert(arr.begin(), 0);

        for(int i = 1; i < arr.size(); ++i)
            arr[i] ^= arr[i-1];

        for(int j = 0; j < arr.size(); ++j)
            for(int k = j+1; k < arr.size(); ++k)
                if(arr[j] == arr[k]) answer += k - j - 1;

        return answer;
    }
};
