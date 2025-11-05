class Solution {
public:
typedef pair<int,pair<int,int>> P;
    int minimumEffortPath(vector<vector<int>>& heights) {
        //lets do it wiht bfs , explore every level, and backstrack to explore every posibility
        int n =heights.size(),m=heights[0].size();
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        priority_queue<P,vector<P>,greater<P>>q;
        q.push({0,{0,0}});
        vector<vector<int>> diff(n,vector<int>(m,INT_MAX));
        diff[0][0]=0;

        while(!q.empty()) // n * m
        {
            auto it = q.top();
            q.pop();
            int dif = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i =0;i<4;i++) 
            {
                int nrow = dr[i]+r;
                int ncol = dc[i]+c;

                if(nrow<n && nrow>=0 && ncol<m && ncol>=0 )
                {
                    int maxDiff = abs(heights[nrow][ncol]-heights[r][c]);
                    int maxEffort = max(dif,maxDiff); // bfs har ek level ke liye maxEffort alaag hoga
                    if(diff[nrow][ncol]>maxEffort)
                    {   diff[nrow][ncol]=maxEffort;
                        q.push({maxEffort,{nrow,ncol}});// log (m*n)
                    }
                    
                }
            }
        }
        return diff[n-1][m-1];
        // tc (m*n(log (m*n)))
        // sc (m*m)
    }
};
