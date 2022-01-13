class Solution {
public:
    int dp[301][5001];
    
    int combinations(vector<int> &v, int idx, int wt)
    {
        if(wt==0) return 1;
        if(idx == v.size() or wt<0) return 0;
        // if(v[idx]<wt)
        // {
        //     return combinations(v, idx+1, wt);
        // }
//         else
//         {
        if(dp[idx][wt] != -1)
        {
            return dp[idx][wt];
        }
        else
        {
        
        return dp[idx][wt] = combinations(v, idx, wt-v[idx]) + combinations(v, idx+1, wt);
        }
        
        
        
    }
    int change(int amount, vector<int>& coins) {
        // if(coins.size()==1) return 1;
        memset(dp, -1, sizeof(dp));
        if(coins.size() ==0) return 0;
        return combinations(coins, 0, amount);
    }
};