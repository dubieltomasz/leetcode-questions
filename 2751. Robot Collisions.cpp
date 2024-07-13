class Solution {
public:
    std::vector<int> survivedRobotsHealths(const std::vector<int>& positions, std::vector<int>& healths, const std::string& directions) {
        std::size_t n = positions.size();
        std::vector<int> answer, indices(n);
        std::stack<int> st;
        int top;

        for(int i = 0; i < n; ++i)
            indices[i] = i;
        
        std::sort(indices.begin(), indices.end(), [&](int a, int b){ return positions[a] < positions[b]; });

        for(const int& index : indices)
        {
            if(directions[index] == 'R') st.push(index);
            else
            {
                while(!st.empty() && healths[index] > 0)
                {
                    top = st.top();
                    st.pop();

                    if(healths[top] > healths[index])
                    {
                        --healths[top];
                        healths[index] = 0;

                        st.push(top);
                    }
                    else if(healths[top] < healths[index])
                    {
                        healths[top] = 0;
                        --healths[index];
                    }
                    else
                    {
                        healths[top] = 0;
                        healths[index] = 0;
                    }
                }
            }
        }

        for(const int& health : healths)
            if(health) answer.push_back(health);

        return answer;
    }
};
