class Solution {
public:
    // int static dp[1001][1001];
    int LCS(string t1, string t2, int n1, int n2)
    {
        // memoization
//         if(n1==0 or n2==0)
//         {
//             return 0;
//         }
     vector<vector<int>> dp(n1+1, vector<int>(n2+1,-1));
//         if(dp[n1][n2] !=-1) return dp[n1][n2];
    
//         if(t1[n1-1] == t2[n2-1])
//         {
//             return dp[n1][n2] = 1+LCS(t1,t2,n1-1,n2-1);
//         }
        
//         return dp[n1][n2] =  max(LCS(t1,t2,n1,n2-1), LCS(t1,t2,n1-1,n2));
        
        // top down appraoch
        // for(int i=0;i<n1;i++)
        // {
        //     dp[i][0] = 0;
        // }
        // for(int j = 0;j<n2;j++)
        // {
        //     dp[0][j] = 0;
        // }
        for(int i=0;i<n1+1;i++)
        {
            for(int j=0;j<n2+1;j++)
            {
                if(i==0 or j==0) dp[i][j] = 0;
            }
        }
        for(int i=1;i<n1+1;i++)
        {
            for(int j=1;j<n2+1;j++)
            {
                if(t1[i-1]==t2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]  = max(dp[i-1][j], dp[i][j-1]);
                }
                
            }
        }
        return dp[n1][n2];

    }
    
    int longestCommonSubsequence(string text1, string text2) {
        // memset(dp,-1,sizeof(dp));
        return LCS(text1, text2, text1.length(), text2.length());
    }
};