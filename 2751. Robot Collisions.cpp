class Solution {
public:
    std::vector<int> survivedRobotsHealths(
        const std::vector<int>& positions,
        std::vector<int>& healths,
        const std::string& directions
    ) {
        #define n healths.size()
        std::vector<int> robots(n);
        
        for(int i = 0; i < n; ++i) {
            robots[i] = i;
        }

        std::sort(robots.begin(), robots.end(),
            [&](const int& a, const int& b) -> bool {
                return positions[a] < positions[b];
            }
        );

        std::stack<int> st;

        for(int robot : robots) {
            switch(directions[robot]) {
                case 'L':
                    while(!st.empty() && healths[robot] != 0) {
                        if(healths[st.top()] == healths[robot]) {
                            healths[st.top()] = 0;
                            st.pop();
                            healths[robot] = 0;
                        } else if(healths[st.top()] > healths[robot]) {
                            --healths[st.top()];
                            healths[robot] = 0;
                        } else {
                            healths[st.top()] = 0;
                            st.pop();
                            --healths[robot];
                        }
                    }
                    break;
                case 'R':
                    st.push(robot);
                    break;
            }
        }
        
        int i = 0;
        for(int j = 0; j < n; ++j) {
            if(healths[j] != 0) {
                robots[i++] = healths[j];
            }
        }
        robots.resize(i);

        return robots;
    }
};
