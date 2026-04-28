class Solution {
  public:
    vector<int> JobScheduling(Job arr[], int n) {
        
        vector<pair<int,int>> jobs;   // renamed to avoid conflict
        
        for(int i = 0; i < n; i++){
            int deadline = arr[i].deadline;   // fixed access
            int profit = arr[i].profit;       // fixed access
            jobs.push_back({deadline, profit});
        }
        
        auto lambda  = [&](auto &a, auto &b){
            return a.second > b.second;
        };  // added semicolon
        
        sort(jobs.begin(), jobs.end(), lambda);
        int maxi =0;
        for(int i=0;i<n;i++){
            maxi = max(jobs[i].first,maxi);
        }
        vector<int> temp(maxi+1,-1);
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            int j=jobs[i].first;
            int profit = jobs[i].second;
            
                while(j>0){
                    if(temp[j]==-1){
                        temp[j]=j;
                        sum+=profit;
                        count++;
                        break;
                    }
                    j--;
                }
        }
        return {count,sum};
        
    }
};
