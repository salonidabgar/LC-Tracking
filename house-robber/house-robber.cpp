class Solution {
public:
    int solver(int st, int end, vector<int> & nums, vector<int> dp)
   {
       int n = nums.size(),i;
       if(n==1) return nums[0];
       dp[st] = nums[st];
       dp[st+1] = max(nums[st], nums[st+1]);
                      ;
       for(i = st+2; i<end; i++)
       {
           dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
       }
       return dp[end-1];
   }
       
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        return solver(0,n,nums, dp);
//         int n = nums.size();
//         if(nums.size()==1)
//         {
//             return nums[0];
//         }
      
//         int dp[n+1];
//         dp[0] = nums[0];
//         dp[1] = max(nums[0], nums[1]);
        
//         for(int i=2;i<n;i++)
//         {
//             dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
//         }
        
//         return dp[n-1];
        
        
        
        
        
        
        
        
        
        
    
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
   }
};