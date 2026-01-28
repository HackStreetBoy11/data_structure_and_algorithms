class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            
            if(arr[i]<0)
            {
                q.push(i);
            }
            
            if(!q.empty() && q.front()<= i-k) // 2   i = 4 , 2<= 4-2
            {
                q.pop ();
            }
            
            if(i>=k-1)  // 0 , 1 , 2, 3, k=2 , i>=k-1
            {
                if(q.empty())
                {
                    ans.push_back(0);
                }
                else{
                    ans.push_back(arr[q.front()]);
                }
            }
        }
        return ans;
    }
};
