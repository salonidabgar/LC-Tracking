class Solution {
public:
    int singleNumber(vector<int>& nums) {
//        unordered_map<int, int> mp;
//         for(auto i: nums)
//         {
//             mp[i]++;
//         }
        
//         for(auto x: mp)
//         {
//             if(x.second == 1) return x.first;
//         }
//         return -1;
        int res = 0;
        for(int i=0;i<nums.size();i++)
        {
            res = res xor nums[i];
        }
        return res;
    }
};