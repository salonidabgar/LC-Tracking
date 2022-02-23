class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n,-1);
        stack<pair<int, int>> st;
        st.push({nums[0], 0});
        
        
        for(int i=1;i<n;i++)
        {
            while(!st.empty() and nums[i]> st.top().first)
            {
                v[st.top().second] = nums[i];
                st.pop();
            }
            st.push({nums[i], i});
        }
        
        for(int i=0;i<n;i++)
        {
            if(st.empty())
                break;
            
            if(nums[i] > st.top().first)
            {
                while(!st.empty() && st.top().first < nums[i])
                {
                    v[st.top().second] = nums[i];
                    st.pop();
                }
            }
        }
        return v;
    }
};