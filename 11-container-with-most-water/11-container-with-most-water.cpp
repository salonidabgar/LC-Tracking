class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int i =0, j = n-1, water =0;
        while(i<j)
        {
            water = max(water, (min(h[i], h[j]) * (j-i)));
            if(h[i] < h[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return water;
    }
};