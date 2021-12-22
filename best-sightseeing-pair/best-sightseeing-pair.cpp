class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int n = values.size();
        vector<int> dp(n+1,0);
        // if(n==0) return 0;
        
        
        int maxscore = INT_MIN, curr = INT_MIN;
        
        for(int i = n-1; i>=0;i--)
        {
            curr = max(curr, values[i]-i);
            dp[i] = curr;
            // cout<<dp[i]<<endl;
        }
        
        for(int i=0;i<n-1;i++)
        {
            int score = values[i] + i + dp[i+1];
            maxscore = max(maxscore, score);
        }
        return maxscore;
    }
};