class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[0] =0;
        int j = 0, i = 1;
        while(i<n)
        {
            if(s[j] == s[i]) dp[++i] = ++j;
            else if(j == 0) i++;
            else j = dp[j];
        }
        // for(auto i: dp)
        // {
        //     cout << i<<" ";
        // }
        return dp[n] and (dp[n] %(n - dp[n]) == 0);
    }
};