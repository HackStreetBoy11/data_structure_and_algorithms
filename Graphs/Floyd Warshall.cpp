class Solution {
public:
    void floydWarshall(vector<vector<int>> &dist) {
        for(int via = 0; via < dist.size(); via++){
            for(int r = 0; r < dist.size(); r++){
                for(int c = 0; c < dist[0].size(); c++){
                    if(dist[r][via] < 1e8 && dist[via][c] < 1e8){
                        dist[r][c] = min(dist[r][c], dist[r][via] + dist[via][c]);
                    }
                }
            }
        }
    }
}; // ✅ THIS WAS MISSING
