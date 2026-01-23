class Solution {
public:
    int max_sum = 0;

    void find_nsl(vector<int>& nsl, vector<int>& height) {
        stack<int> st;
        for(int i = 0; i < height.size(); i++) {
            while(!st.empty() && height[st.top()] >= height[i]) {
                st.pop();
            }
            nsl[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    void find_nsr(vector<int>& nsr, vector<int>& height) {
        stack<int> st;
        int n = height.size();
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && height[st.top()] >= height[i]) {
                st.pop();
            }
            nsr[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    void fun_calc(vector<int>& height) {
        int n = height.size();
        vector<int> nsl(n), nsr(n);

        find_nsl(nsl, height);
        find_nsr(nsr, height);

        for(int i = 0; i < n; i++) {
            int width = nsr[i] - nsl[i] - 1;
            int area = min(height[i] , width);
            max_sum = max(max_sum, area*area);
        }
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        vector<int> height(c, 0);

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                height[j] = (matrix[i][j] == '0') ? 0 : height[j] + 1;
            }
            fun_calc(height);  
        }

        return max_sum;
    }
};
