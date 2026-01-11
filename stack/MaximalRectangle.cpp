class Solution {
public:
    void fun_NLR(vector<int>&NLR,vector<int>& height){
        int n=height.size();
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && height[st.top()]>=height[i]){
                st.pop();
            }
            NLR[i]= st.empty()?n:st.top();
            st.push(i);
        }       
        return ;
    }
    void fun_NLL(vector<int>&NLL,vector<int>& height){
        int n=height.size();
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && height[st.top()]>=height[i]){
                st.pop();
            }
            NLL[i]= st.empty()?-1:st.top();
            st.push(i);
        }       
        return ;
    }
    int find_fun(vector<int> &height){
        int n = height.size();
        vector<int> NLR(n);
        vector<int> NLL(n);
        fun_NLR(NLR,height);
        fun_NLL(NLL,height);
        int maxi =0;
        for(int i =0;i<height.size();i++)
        {
            int widht = NLR[i]-NLL[i]-1;
            maxi = max(maxi,widht*height[i]);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int> height(col,0);
        int maxHeight=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                height[j]= (matrix[i][j]=='0')?0:height[j]+1;
            }
            maxHeight=max(maxHeight,find_fun(height));
        }
        return maxHeight;
    }
};
