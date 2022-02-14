class Solution {
public:
   int lastStoneWeightII(vector<int>& stones) {
//         int n = stones.size(),sum=0;
//         for(auto i: stones)
//         {
//             sum+=i;
//         }
//         vector<vector<int>> dp(n+1, vector<int>(sum/2 + 1,-1));
//         int s;
//         for(int i=1;i<=n;i++)
//         {
//             for(int j= 1;j<=sum/2;j--)
//             {
//                 if(stones[i-1] > j) dp[i][j] = dp[i-1][j];
//                 else
//                 {
                
//                     dp[i][j] = max( dp[i-1][j-stones[i-1]] + stones[i-1], dp[i-1][j]);
//                 }
//             }
//         }
//         return (sum- (2*dp[n][sum/2]));
//     }
        int sum = 0;
    int total = 0;
    int n = stones.size();
    for(int i = 0;i<n;i++) {
        total+=stones[i];
    }
    sum = total/2;
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    for(int i =1;i<=n;i++) {
        for(int j = 1;j<=sum;j++) {
            if(stones[i-1]>j) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-stones[i-1]]+stones[i-1]);
            }
        }
    }
    return total-(2*dp[n][sum]);
}
};