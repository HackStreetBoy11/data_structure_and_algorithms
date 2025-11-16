class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        queue<int> q;
        
        int l=0,r=0;
        vector<int> ans;
        while(r<arr.size())
        {
            if(arr[r]<0)
            {
                q.push(r);
            }
            if(r-l+1==k)
            {
                if(!q.empty())
                {
                    ans.push_back(arr[q.front()]);
                }
                else{
                    ans.push_back(0);
                }
                
                if(arr[l]<0)
                {
                    q.pop();
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};
