class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size(),sum=0;
        for(int i = 0;i<n;i++) {
        sum+=stones[i];
    }
        int total = sum/2;
        vector<vector<int>> dp(n+1, vector<int>(total + 1,0));
        int s;
        for(int i=1;i<=n;i++)
        {
            for(int j= 1;j<=total;j++)
            {
                if(stones[i-1] > j) dp[i][j] = dp[i-1][j];
                else
                {
                
                    dp[i][j] = max( dp[i-1][j-stones[i-1]] + stones[i-1], dp[i-1][j]);
                }
            }
        }
        return (sum- (2*dp[n][total]));
    }
};