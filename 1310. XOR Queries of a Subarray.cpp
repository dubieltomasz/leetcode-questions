class Solution {
public:
    std::vector<int> xorQueries(std::vector<int>& arr, const std::vector<std::vector<int>>& queries) {
        std::vector<int> answer;

        answer.reserve(queries.size());
        
        arr.insert(arr.begin(), 0);

        for(int i = 1; i < arr.size(); ++i)
            arr[i] ^= arr[i-1];
        
        for(const std::vector<int>& query : queries)
            answer.push_back(arr[query[0]] ^ arr[query[1]+1]);

        return answer;
    }
};
