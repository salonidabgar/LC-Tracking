class Solution {
public:
  
    int LCS(string a, string b, int n, int m)
    {
        vector<vector<int>> dp(n+2, vector<int>(m+2,-1));
         for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 or j==0) dp[i][j] =0;
            }
         }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                
                if(a[i-1]==b[j-1])
                {
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
            
    }
    int longestPalindromeSubseq(string s) {
        string s_rev;
        int n = s.length();
        for (int i = n - 1; i >= 0; i--) 
        s_rev.push_back(s[i]);
        return LCS(s,s_rev, s.length(), s_rev.length());
    }
};