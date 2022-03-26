class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        int n = nums.size();
        int second = n-1, zero =0;
        for(int i=0;i<n;i++)
        {
            while(nums[i]==2 and i<second) swap(nums[i], nums[second--]);
            while(nums[i]==0 and i> zero) swap(nums[i], nums[zero++]);
        }
            
    }
};