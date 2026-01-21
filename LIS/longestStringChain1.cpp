class Solution {
public:
bool is_pred(const string &parent, const string &child) {
        int i = 0, j = 0;
        while (i < parent.size()) {
            if (j < child.size() && parent[i] == child[j]) {
                j++;
            }
            i++;
        }
        return j == child.size();
    }
    int longestStrChain(vector<string>& words) {
         sort(words.begin(), words.end(),
             [](const string &a, const string &b) {
                 return a.size() < b.size();
             });

        int n = words.size();
        vector<int> dp(n, 1);
        int maxlen = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (words[i].size() - words[j].size() == 1 &&
                    is_pred(words[i], words[j])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxlen = max(maxlen, dp[i]);
        }
        return maxlen;
    }
};
