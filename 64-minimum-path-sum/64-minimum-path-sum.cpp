class Solution {
public:
    
    int minPathSum(vector<vector<int>>& g) {
        
        int m = g.size();
        int n = g[0].size();
        
        vector<int> curr(m, g[0][0]);
        
        for(int i=1;i<m;i++)
        {
            curr[i] = curr[i-1]  + g[i][0];
        }
        for (int j = 1; j < n; j++) {
            curr[0] += g[0][j]; 
            for (int i = 1; i < m; i++)
                curr[i] = min(curr[i - 1], curr[i]) + g[i][j];
        }
        return curr[m - 1];
 
    }
};