class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        //  will sort on the basis of starting time
        // in the basis of collision , i will add a platform 
        // and nullify when the minimum endtime 
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int n =arr.size();
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            ans[i].push_back(arr[i]);
            ans[i].push_back(dep[i]);
        }
        
        auto lambda = [&](auto &a, auto &b){
            return a[0]<b[0];
        };
        sort(ans.begin(),ans.end(),lambda);
        pq.push(ans[0][1]);
        int needed=1;
        for(int i=1;i<n;i++){
           while(!pq.empty() &&  pq.top()< ans[i][0]){
               pq.pop();
           }
           pq.push(ans[i][1]);
           needed = max(needed,(int) pq.size());
        }
        return needed;
    }
};
