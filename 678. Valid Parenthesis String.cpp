static const void __attribute__((constructor)) fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class Solution {
public:
    bool checkValidString(const string& s) {
        int l = 0, rw = 0, lw = 0;
        for(const char& c : s)
        {
            switch(c)
            {
                case '(':
                    ++l;
                    break;
                case ')':
                    if(l > 0) --l;
                    else if(lw > 0)
                    {
                        --lw;
                        ++rw;
                    }
                    else if(rw > 0) --rw;
                    else return false;
                    break;
                default:
                    if(l > 0)
                    {
                        --l;
                        ++lw;
                    }
                    else ++rw;
                    break;
            }
        }

        return !l;
    }
};
