class Solution {
public:
    int editdist(string w1, string w2, int l1, int l2)
    {
        vector<vector<int> > dp(l1+1, vector<int>(l2+1,0));
        int count1=0, count2 =0;
        for(int j=0;j<=l2;j++)
        {
            dp[0][j] = count1;
            count1++;
        }
        for(int i=0;i<=l1;i++)
        {
            dp[i][0] = count2;
            count2++;
        }
        for(int i = 1; i<=l1 ; i++)
        {
            for(int j = 1; j<=l2 ;j++)
            {
                if(w1[i-1] == w2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = 1+ min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
                }
            }
        }
        return dp[l1][l2];
    }
    int minDistance(string word1, string word2) {
        return editdist(word1, word2, word1.size(), word2.size());
    }
};