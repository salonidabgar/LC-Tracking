class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n,0), right(n,0);
        left[0] = height[0], right[n-1] = height[n-1];
        for(int i=1;i<n;i++)
        {
            // cout <<"hi";
            left[i] = max(height[i], left[i-1]);
            
        }
        
        for(int i=n-2;i>=0;i--)
        {
            right[i] = max(height[i], right[i+1]);
        }
        int water = 0;
        // for(int i=0;i<n;i++)
        // {
        //     cout << left[i]<<" "<<right[i]<<endl;
        // }
        for(int i=1;i<n-1;i++)
        {
            int cap = min(left[i-1], right[i+1]) ;
            if(cap >= height[i])
            water+= (cap-height[i]);
        }
        return water;
    }
};