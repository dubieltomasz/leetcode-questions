class Solution {
public:
    int countLargestGroup(const int& n) {
        int arr[37]{}, largest = 0, answer = 0;

        for(int i = 1; i <= n; ++i)
        {
            int tmp = i, sum = 0;

            while(tmp)
            {
                sum += tmp % 10;
                tmp /= 10;
            }
            
            if(0 < sum && sum < 38)
                ++arr[sum-1];
        }

        for(int i = 0; i < 37; ++i)
        {
            if(arr[i] > largest)
            {
                largest = arr[i];
                answer = 1;
            }
            else if(arr[i] == largest)
                ++answer;
        }

        return answer;
    }
};
