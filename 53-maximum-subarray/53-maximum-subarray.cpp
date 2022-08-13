class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int n = v.size();
        vector<int> maxsum(n,0);
        maxsum[0] = v[0];
        for(int i=1;i<n;i++)
        {
            maxsum[i] = maxsum[i-1] + v[i];
            if(maxsum[i] < v[i])
            {
                maxsum[i] = v[i];
            }
        }
        return *max_element(maxsum.begin(), maxsum.end());
    }
};