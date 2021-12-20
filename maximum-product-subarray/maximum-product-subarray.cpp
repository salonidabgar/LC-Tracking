class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int n = nums.size(); 
        // currprod = nums[0], maxprod = nums[0];
//         if(n==1) return nums[0];
//         for(int i=1;i<n;i++)
//         {
//             currprod = max(currprod*nums[i], nums[i]);
//             // if(currprod<0) currprod =0;
//             maxprod= max(currprod, maxprod);
//         }
//         return maxprod;
        int res = *max_element(nums.begin(), nums.end()), currmin = 1, currmax = 1, temp;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                currmin =1;
                currmax =1;
                continue;
            }
            temp = currmax*nums[i];
            currmax = max(nums[i] * currmax, max(nums[i]* currmin, nums[i]));
            currmin = min(temp, min(nums[i]* currmin, nums[i]));
            res = max(res, currmax);
              
        }
        
        return res;
    }
};