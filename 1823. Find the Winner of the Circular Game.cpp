class Solution {
public:
    int findTheWinner(int n, const int& k) {
        std::vector<int> v(n);
        int i = 0;

        for(int j = 0; j < n; ++j)
            v[j] = j+1;

        while(n > 1)
        {
            i = (i+k-1) % n--;

            v.erase(v.begin()+i);
        }

        return v.front();
    }
};
