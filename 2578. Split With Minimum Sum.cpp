class Solution {
public:
    int splitNum(int num) {
        int arr[10] = {};
        int num1 = 0, num2 = 0;
        bool first = true;

        while(num) {
            ++arr[num % 10];
            num /= 10;
        }

        for(int i = 0; i < 10; ++i) {
            while(arr[i]--) {
                if(first) {
                    num1 *= 10;
                    num1 += i;
                } else {
                    num2 *= 10;
                    num2 += i;
                }

                first = !first;
            }
        }

        return num1 + num2;
    }
};
