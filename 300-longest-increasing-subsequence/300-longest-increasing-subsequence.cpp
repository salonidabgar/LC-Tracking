class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        vector<int> sol;
        sol.push_back(v[0]);
        for(int i=1;i<v.size();i++)
        {
            if(sol.back() < v[i]) sol.push_back(v[i]);
            else
            {
                int idx = lower_bound(sol.begin(), sol.end(), v[i]) - sol.begin();
                sol[idx] = v[i];
            }
        }
        
            return sol.size();

    }
};