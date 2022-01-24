class Solution {
public:
//     int solver(vector<vector<int>>& v, int i, int j)
//     {
//         int m = v.size();
//         int n = v[0].size();
//         vector<vector<int>> dp(m, vector<int>(n,0));
        
//         if(i<0 or j<0 or i>=m or j>=n) return 0;
//         if(dp[i][j]) return dp[i][j];
//         if(v[i][j]) return dp[i][j] = 0;
//         if(i ==m-1 and j == n-1 and !v[i][j]) return 1;
//         else
//             return dp[i][j] = solver(v,i+1, j) + solver(v,i,j+1);
 
//     }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid ) {
        
        // return solver(v, 0,0);
        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][1] = 1;
        for(int i = 1 ; i <= m ; ++i)
            for(int j = 1 ; j <= n ; ++j)
                if(!obstacleGrid[i-1][j-1])
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
        return dp[m][n];
        
        
    }
};