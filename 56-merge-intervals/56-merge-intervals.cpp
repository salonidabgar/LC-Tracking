class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> sol;
        sort(intervals.begin(), intervals.end());
        vector<int> ans ={intervals[0][0], intervals[0][1]};
        int n = intervals.size();
        if(n==1) 
        {
            sol.push_back(ans);
            return sol;
        }
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<=ans[1])
            {
                if(intervals[i][0]<ans[0])
                {
                    ans[0] = intervals[i][0];
                }
                if(intervals[i][1] >ans[1])
                {
                    ans[1] = intervals[i][1];
                }
            }
            else
            {
                sol.push_back(ans);
                ans = {intervals[i][0], intervals[i][1]};
                // continue;
            }
            
        }
        sol.push_back(ans);
        return sol;
    }
};