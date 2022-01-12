// class Solution {
// public:
//     bool solve(vector<int> & nums, int target, int idx)
//     {
        
//         int n = nums.size();
//         int dp[n+1][target+1];
//         // if(target==0) return 1;
//         // dp[0] = true;
//         // dp[n] = false;
//         // if(target<0) return 0;
        
//         for(int i=0;i<n;i++)
//         {
//             dp[i][0] = true;
//         }
//         for(int j=0;j<target;j++)
//         {
//             dp[0][j]= false;
//         }
        
//         for(int i = 1; i<=n;i++)
//         {
//             for(int j = 1;j<=target;j++)
//             {
//                 if(nums[i-1]>j)
//                 {
//                     dp[i][j] = dp[i-1][j];
//                 }
//                 else
//                 {
//                     dp[i][j] = dp[i+1][j] or dp[i+1][j-nums[i-1]];
//                 }
//             }
//         }
        
//         return dp[n][target];
//         // return dp[idx] = solve(nums,target-nums[idx], idx+1 ) or solve(nums, target, idx+1);  
        
        
//     }
        class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sum = accumulate(nums.begin(), nums.end(), sum);
       
        return (sum%2==0) && solve(nums, sum/2);
    }
private:
    int sum = 0;
    
    bool solve(vector<int> &nums, int sum){
        int n = nums.size();
        bool dp[n+1][sum + 1];
        
        for(int i=0;i<=n;i++) dp[i][0] = true; //subset with 0 sum
        
        for(int j=1;j<=sum;j++) dp[0][j] = false; //non-zero sum with 0 elements
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1] > j) dp[i][j] = dp[i-1][j]; //don't include ith element if it's greater then the rem sum
                else dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
               
            }
        }
        
        return dp[n][sum];
        
        
    }
};
//     bool canPartition(vector<int>& nums) {
// //        int n = nums.size(),sum;
// //         vector<bool> dp(sum+1, false);
        
// //         dp[0] = true;
        
// //         for (auto num : nums) {
// // 			for (int j = sum; j >= num; j--) {
// // 				if(dp[j-num] || j == num) dp[j] = true; 
// // 			}
// // 		}
// //         return dp[sum];
//          int sum= 0;
//         for(auto i : nums)
//         {
//             sum +=i;
//         }
//         // cout<<sum<<endl;
//         return ((sum%2==0) and solve(nums, sum/2, 0));
        
//     }
// };