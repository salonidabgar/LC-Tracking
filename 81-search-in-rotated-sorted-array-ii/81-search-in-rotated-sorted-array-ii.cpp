class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int left =0, right = n-1;
        
        while(left<right)
        {
            int mid = left+(right-left)/2;
            
            if(nums[mid]==target) return true;
            
            else if(nums[left]<nums[mid])
            {
                if(target<nums[mid] and target>=nums[left])
                {
                    right = mid-1;
                }
                else
                {
                    left = mid+1;
                }
            } 
            else if(nums[right]>nums[mid])
            {
                if(target> nums[mid] and target<=nums[right])
                {
                    left = mid+1;
                }
                else
                {
                    right = mid-1;
                }
            }
            else
            {
                if(nums[left] == nums[mid]) left++;
                if(nums[right] == nums[mid]) right--;
            }
        }
        if(left==right)
        {
            if(nums[left] == target) return true;
            
        }
        return false;
    }
};