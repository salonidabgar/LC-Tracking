class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<pair<int, int>> st;
        vector<int> v(nums2.size(), -1) ,ans;
        
        st.push({nums2[0],0});
        
        for(int i =1;i<nums2.size();i++)
        {
            
            while(!st.empty() and nums2[i] > st.top().first)
            {
                v[st.top().second] = nums2[i];
                st.pop();
                // st.push(nums2[i]);
                // cout<<v[i-1]<< endl;
                
            }
                st.push({nums2[i],i});
                // cout<<2<<endl;
        
            // cout<<v[i]<<" ";
        }
        int t = st.top().first;
        st.pop();
        while(!st.empty())
        {
            if(st.top().first < t)
            v[st.top().second] = t;
            st.pop();
        
        }
        // v[nums2.size()-1] = -1;
        // for(auto i :v)
        // {
        //     cout<<i<<" ";
        // }
        //storing indices of elements in nums2
        
        unordered_map<int, int> m;
        for(int i=0;i<nums2.size();i++)
        {
            m[nums2[i]] = i;
            
        }
        // for(auto i:m)
        // {
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        
        for(int i =0;i<nums1.size();i++)
        {
            auto it = m.find(nums1[i]);
            if( it !=m.end())
            {   
                // cout<<it->second<<endl;
                ans.push_back(v[it->second]);
            }
        }
        return ans;
    }
};