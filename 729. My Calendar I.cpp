class MyCalendar {
public:
    MyCalendar() {

    }
    
    bool book(const int& start, const int& end) {
        int l = 0, r = v.size()-1, m;

        while(l <= r)
        {
            m = (r+l)/2;

            if(start < v[m]->start && v[m]->end < end || v[m]->start <= start && start < v[m]->end || v[m]->start < end && end <= v[m]->end)
                return false;
            else if(v[m]->end <= start) l = m+1;
            else r = m-1;
        }

        v.insert(v.begin()+l, new event(start, end));

        return true;
    }

private:
    struct event{
        int start;
        int end;

        event(const int& s, const int& e)
        {
            start = s;
            end = e;
        }
    };

    std::vector<event*> v;
};
