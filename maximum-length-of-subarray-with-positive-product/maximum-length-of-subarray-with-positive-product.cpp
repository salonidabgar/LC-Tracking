class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size(), neg=0, pos =0, ans=0;
        
        for(auto x: nums)
        {
            if(x==0)
            {
                pos =0;
                neg =0;
            }
            else if(x>0)
            {
                pos++;
                neg = neg==0 ? 0: neg+1;
            }
            else
            {
                int temp = pos;
                pos = neg==0 ? 0: neg+1;
                neg = temp+1;
            }
            ans = max(ans, pos);
        }
        return ans;
        
        
    }
};