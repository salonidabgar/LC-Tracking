class Solution {
public:
//     int subarrays(int idx, int  k, vector<int> & nums, int count)
//     {
//         // int count;
//         if(nums.size() == 0 ) return 0;
//         if(idx>=nums.size()) return count;
//         if(k==0) 
//         {
//             cout<<1<<endl;
            
//             return subarrays(idx+1, k, nums,count++);
//         }
//         if(nums[idx]<=k)
//         {
//             cout<<2<<endl;
//             subarrays(idx+1, k-nums[idx], nums,count);
//         }
//         else
//         {
//             subarrays(idx+1, k, nums,count);
//         }
//         return 0;
//     }
    int subarraySum(vector<int>& nums, int k) {
        // return subarrays(0, k,nums,0);
        
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        mp[sum] = 1;
        for(auto it:nums){
            sum += it;
            int find = sum - k;
            if(mp.find(find) != mp.end()){
                ans += mp[find];
            }
            mp[sum]++;
        }
        return ans;
//PLEASE UPVOTE IF YOU LIKE MY SOLUTION  :)
    
    }
};