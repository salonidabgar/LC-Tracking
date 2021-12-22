class Solution {
public:
    int maxProfit(vector<int>& nums) {
       int n = nums.size(), maxele = INT_MIN, maxprofit;
       vector<int> dp(n+2, -1);
       for(int i=n-1;i>=0;i--)
       {
           // dp[i] = *max_element(prices.begin() + i , prices.end());
           maxele = max(nums[i], maxele);
           dp[i] = maxele;
           // cout<<dp[i]<<endl;
           
       }
       for(int i=0;i<n-1;i++)
       {
               int profit = dp[i+1] > nums[i] ? dp[i+1]-nums[i] : 0;
               cout<<profit<<endl;
               maxprofit = max(profit, maxprofit);
               
          
       }
        return maxprofit;
    
    }
};