class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // using a map to store frequencies
        map<int, int> mp;
        for(auto it: nums)
        {
            mp[it]++;
        }
        int ans=0;
        for(auto it: mp)
        {
            if( (k>0 and (mp.find(it.first + k) != mp.end() ) ) or(k==0 and it.second >1))
               {
                   ans++;
               }
        }
        return ans;
    }
};