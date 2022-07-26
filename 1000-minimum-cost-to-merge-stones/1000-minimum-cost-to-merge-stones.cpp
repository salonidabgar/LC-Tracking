class Solution {
public:
    
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if((n-1)%(k-1)) return -1;
        vector<int> prefix(n+1);
        for(int i=0;i<n;i++)
        {
            prefix[i+1] = prefix[i] + stones[i];
        }
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int m = k;m<=n;m++)
        {
            for(int i=0; i+m<=n;i++)
            {
                int j = i+m-1;
                dp[i][j] = INT_MAX;
                for(int mid = i;mid <j; mid +=(k-1))
                {
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid+1][j]);
                }
                if((j-i)%(k-1) == 0)
                {
                    dp[i][j] += prefix[j+1] - prefix[i];
                }
            }
        }
        return dp[0][n-1];
        
    }
};