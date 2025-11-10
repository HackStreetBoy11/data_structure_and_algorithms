class Solution {
public:
// on increasing insert operation
// on decreasing pop the value from the stack
// if empty() add operation
    int minOperations(vector<int>& nums) {
        stack<int>st;
        int op=0;
        for(int i=0;i<nums.size();i++)
        {   
            while(!st.empty() && st.top()>nums[i])
            {
                st.pop();
            }
            if(nums[i]==0)continue;
            if(st.empty() || st.top()<nums[i]){
                st.push(nums[i]);
                op++;
            }
        }
        return op;
    }
};
