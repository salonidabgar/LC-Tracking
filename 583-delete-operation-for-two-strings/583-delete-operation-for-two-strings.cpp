class Solution {
public:
    int LCS(string w1, string w2, int len1, int len2)
    {
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        // int count =0;
        for(int i=0;i<=len1;i++)
        {
            for(int j=0;j<=len2;j++)
            {
                if(i==0 or j==0)
                {
                    dp[i][j] = 0;
                }
            }
        }
        for(int i=1;i<=len1;i++)
        {
            for(int j =1;j<=len2;j++)
            {
                if(w1[i-1] == w2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[len1][len2];
    }
    int minDistance(string word1, string word2) {
        return(word1.length() + word2.length() - 2*LCS(word1, word2, word1.length(), word2.length()));
            
    }
};