class MyCalendarTwo {
public:
    MyCalendarTwo() {}
    
    bool book(const int start, const int end) {
        int tmp = 0;

        ++m[start];
        --m[end];

        for(const std::pair<int, int>& p : m)
            if((tmp += p.second) > 2)
            {
                --m[start];
                if(!m[start]) m.erase(start);

                ++m[end];
                if(!m[end]) m.erase(end);

                return false;
            }
        
        return true;
    }

private:
    std::map<int, int> m;
};
