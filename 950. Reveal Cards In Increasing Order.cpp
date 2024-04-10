static const void __attribute__((constructor)) fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size(), i = 0;
        vector<int> answer(n);
        queue<int> q;

        for(int j = 0; j < n; ++j)
            q.push(j);

        sort(deck.begin(), deck.end());

        for(int j = 0; j < n; ++j)
        {
            i = q.front();
            q.pop();

            q.push(q.front());
            q.pop();

            answer[i] = deck[j];
        }

        return answer;
    }
};
