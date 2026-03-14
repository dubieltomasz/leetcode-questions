class Solution {
public:
    std::string getHappyString(int n, int k) {
        std::queue<std::string> q;
        q.push("a");
        q.push("b");
        q.push("c");

        while(--n) {
            int size = q.size();

            for(int i = 0; i < size; ++i) {
                std::string tmp = q.front();
                q.pop();

                switch(tmp.back()) {
                    case 'a' :
                        q.push(tmp + 'b');
                        q.push(tmp + 'c');
                        break;
                    case 'b' :
                        q.push(tmp + 'a');
                        q.push(tmp + 'c');
                        break;
                    case 'c' :
                        q.push(tmp + 'a');
                        q.push(tmp + 'b');
                        break;
                }
            }
        }

        if(k > q.size()) {
            return "";
        }

        while(--k) {
            q.pop();
        }

        return q.front();
    }
};
