class Solution {
public:
    int BinarySearch(vector<int> & nums, int target, int lo, int hi)
    {
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target)
            {
                // cout<< mid<< endl;
                return mid;
            }
            else if(nums[mid] > target)
            {
                hi = mid-1;
            }
            else
            {
                lo = mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0, r=n-1,pivot=0;
        while(l<r)
        {
            int mid = l+(r-l)/2;
            // if(nums[mid] == nums[r])
            // {
            //     pivot = mid;
            //     break;
            // }
            if(nums[mid] < nums[r])
            {
                r = mid;
            }
            else
            {
                l = mid+1;
            }
        }
        pivot = l;
        // cout << pivot<< endl;
        if(target > nums[pivot] and target > nums[n-1])
        {
            return BinarySearch(nums, target, 0, pivot-1);
        }
        return BinarySearch(nums, target, pivot, n-1);
        // return -1;
            
    }
};