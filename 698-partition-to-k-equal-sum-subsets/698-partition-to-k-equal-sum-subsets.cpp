class Solution {
public: //DFS
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int tot = accumulate(nums.begin(), nums.end(), 0);
        if(tot % k != 0) return false;
        int target = tot / k;
        sort(nums.rbegin(), nums.rend()); // without sort: Runtime: 1104 ms; with sort: Runtime: 4 ms
        return dfs(nums, k, target, 0, 0);
    }
    
private:
    bool dfs(const vector<int>& nums, const int k, const int target, const int cur, const int used) {
        const int n = nums.size();
        if(k == 0) return used == (1<<n)-1;
        for(int i = 0; i < n; i++){
            if(used & (1 <<i)) continue;
            int tot = cur + nums[i];
            if(tot > target) break;
            int new_used = used | (1 <<i);
            if( tot == target  && dfs(nums, k-1, target, 0, new_used)) return true;
            else if( tot != target && dfs(nums, k, target, tot, new_used)) return true;
        }
        return false;
    }
};