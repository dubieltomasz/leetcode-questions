static const void __attribute__((constructor)) fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class Solution {
public:
    int countStudents(const vector<int>& students, const vector<int>& sandwiches) {
        int j = 0, n = students.size(), st[2] = {0, 0}, sa[2] = {0, 0};

        for(int i = 0; i < n; ++i)
        {
            ++st[students[i]];
            ++sa[sandwiches[i]];
        }
        
        if(st[0] > sa[0])
        {
            while(st[sandwiches[j]])
                --st[sandwiches[j++]];

            return st[0] + st[1];
        }
        else if(st[1] > sa[1])
        {
            while(st[sandwiches[j]])
                --st[sandwiches[j++]];

            return st[0] + st[1];
        }
        else return 0; 
    }
};
