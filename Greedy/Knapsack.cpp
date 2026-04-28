class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<int,int>> knap;
        for(int i=0;i<val.size();i++){
            knap.push_back({val[i],wt[i]});
        }
        auto lambda = [&](auto &a,auto &b){
            return (double)a.first/a.second>(double)b.first/b.second;
        };
        sort(knap.begin(),knap.end(),lambda);
        double sum=0;
        for(int i=0;i<knap.size();i++){
            if(capacity<=0)break;
            int W = knap[i].second;
            if(W<=capacity){
                sum +=knap[i].first;
                capacity-=W;
            }else{
                sum+= ((double) knap[i].first/W)*capacity;
                capacity=0;
            }
        }
        return sum;
    }
};
