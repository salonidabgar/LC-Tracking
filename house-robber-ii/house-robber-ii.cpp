class Solution {
public:
    int solver(int st, vector<int> & nums, vector<int> &dp)
   {
       int n = nums.size()-1,i;
       
       dp[st] = nums[st];
       dp[st+1] = max(nums[st], nums[st+1]);
        
                   
       for(i = st+2; i< n+st; i++)
       {
           dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
           // cout<<"yes" <<endl;
       }
       return dp[st+n-1];
   }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1)
        {
            return nums[0];
        }
        if(n==2)
        {
            return max(nums[0], nums[1]);
        }
        
        vector<int> dp(n+1,0);
        vector<int> dp2(n+1, 0);
        solver(0,nums,dp) , solver(1,nums, dp2);
        return max(dp[n-2], dp2[n-1]);
    }
                         
};