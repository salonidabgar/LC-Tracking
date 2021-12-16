class Solution {
public:
    
    int climbStairs(int n) {
        // int ways =1;
        // if(n==0 or n==1) return ways;
        // else ways = climbStairs(n-1)  + climbStairs(n-2);
        // return ways;
        
        
        int nums[n+1];
        nums[0] = 1;
        nums[1] = 1;
        
        for(int i =2;i<=n;i++)
        {
            nums[i] = nums[i-1] + nums[i-2];
        }
        
        return nums[n];
        
    }
};