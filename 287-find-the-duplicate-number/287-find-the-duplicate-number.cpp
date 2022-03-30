class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int fast =  nums[nums[0]];
        int slow =  nums[0];
        int entry = 0;
        if(n>1)
        { 
        while(fast!=slow)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(slow!=entry)
        {
            slow = nums[slow];
            entry = nums[entry];
        }
        return slow;
        }
        return -1;
        
    }
};