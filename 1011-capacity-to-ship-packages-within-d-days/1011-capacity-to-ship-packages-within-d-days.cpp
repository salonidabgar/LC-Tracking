class Solution {
public:
    // int partitions(vector<int> &w, int mid)
    // {
    //     int sum=0,p=1;
    //     for(int i=0;i<w.size() and p<=mid;i++)
    //     {
    //         if(sum+w[i]>mid)
    //         {
    //             p++;
    //             sum=0;
    //         }
    //     }
    //     return p;
    // }
    int shipWithinDays(vector<int>& weights, int D) {
        int left = 0, right = 25000000;
        for (int w: weights)
            left = max(left, w);
        while (left < right) {
            int mid = (left + right) / 2, need = 1, cur = 0;
            for (int i = 0; i < weights.size() && need <= D; cur += weights[i++])
                if (cur + weights[i] > mid)
                    cur = 0, need++;
            if (need > D) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};