class Solution {
public:
    bool parseBoolExpr(const std::string& expression) {
        std::stack<char> st;
        bool hasTrue = false, hasFalse = false;
        char top;

        for(const char& c : expression)
        {
            switch(c)
            {
                case ',':
                    break;

                case '(':
                    break;
                
                case ')':
                    top = st.top();
                    st.pop();

                    while(top != '!' && top != '&' && top != '|')
                    {
                        top == 't' ? hasTrue = true : hasFalse = true;

                        top = st.top();
                        st.pop();
                    }

                    switch(top)
                    {
                        case '!':
                            st.push(hasTrue ? 'f' : 't');
                            break;

                        case '&':
                            st.push(hasFalse ? 'f' : 't');
                            break;
                        
                        case '|':
                            st.push(hasTrue ? 't' : 'f');
                            break;
                    }

                    hasTrue = false;
                    hasFalse = false;
                    break;
                
                default:
                    st.push(c);
                    break;
            }
        }

        return st.top() == 't';
    }
};
