class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l=0,r=0,ans=0, maxx ;
        while(r<n-1)
        {
            maxx = nums[0];
            for(int i=l;i<=r;i++)
            {
              maxx = max(maxx, nums[i] + i);  
            }
            l=r+1;
            r=maxx;
            ans++;
        }
        
        return ans;
    }
};