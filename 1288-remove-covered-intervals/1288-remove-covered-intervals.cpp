class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int res =0, l = -1, r = -1;
        sort(intervals.begin(), intervals.end());
        for(auto &i: intervals)
        {
            if(i[0]> l and i[1]> r)
            {
                l = i[0];
                res++;
            }
            r = max(r, i[1]);
        }
        return res;
    }
};