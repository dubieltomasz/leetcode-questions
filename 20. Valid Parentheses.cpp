class Solution {
public:
    bool isValid(const string& s) {
        stack<char> st;

        for(const char& c : s)
        {
            switch(c)
            {
                case '(':
                    st.push('(');
                    break;
                case '[':
                    st.push('[');
                    break;
                case '{':
                    st.push('{');
                    break;
                case ')':
                    if(st.empty() || st.top() != '(') return false;
                    
                    st.pop();
                    break;
                case ']':
                    if(st.empty() || st.top() != '[') return false;
                    
                    st.pop();
                    break;
                case '}':
                    if(st.empty() || st.top() != '{') return false;
                    
                    st.pop();
                    break;
            }
        }

        return st.empty() ? true : false;
    }
};
