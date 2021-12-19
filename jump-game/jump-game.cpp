class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), maxx =nums[0];
        
        for(int i=0;i<n && i<= maxx ;i++)
        {
            
           
              maxx = max(maxx, nums[i]+i);  

            
            // cout<< maxx<<endl;
        }
        
    if(maxx>= n-1)
        return true;
        
        return false;
       
        
    }
};