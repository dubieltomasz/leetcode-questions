class KthLargest {
public:
    KthLargest(const int k, const std::vector<int>& nums) {
        size = k;

        for(const int& num : nums)
            pq.push(num);

        while(pq.size() > size)
            pq.pop();
    }
    
    int add(const int val) {
        pq.push(val);

        if(pq.size() > size)
            pq.pop();
        
        return pq.top();
    }

private:
    int size;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
};
